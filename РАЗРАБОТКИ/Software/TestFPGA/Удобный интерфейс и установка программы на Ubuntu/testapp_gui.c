#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>
#include <time.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <pthread.h>

// Включаем заголовочный файл с определениями регистров
#include "nettimelogic.h"

// Глобальные переменные для GUI
GtkWidget *window;
GtkWidget *entry_pcie_addr;
GtkWidget *button_connect;
GtkWidget *button_disconnect;
GtkWidget *button_start_stop;
GtkWidget *status_bar;

// Метки для версий IP-ядер
GtkWidget *label_fpga_version;
GtkWidget *label_clock_version;
GtkWidget *label_signal_ts1_version;
GtkWidget *label_signal_ts2_version;
GtkWidget *label_pps_master_version;
GtkWidget *label_pps_slave_version;
GtkWidget *label_tod_slave_version;

// Метки для статуса
GtkWidget *label_clock_status;
GtkWidget *label_clock_source;
GtkWidget *label_gpio_status;
GtkWidget *label_pps_pulse_width;

// Индикаторы GPIO (8 битов)
GtkWidget *gpio_indicators[8];

// Переменные для работы с FPGA
void *pcie_base = NULL;
unsigned mapped_size = 0;
int fd = -1;
uint32_t pcie_addr = 0;

// Флаги состояния
gboolean is_connected = FALSE;
gboolean is_monitoring = FALSE;
pthread_t monitor_thread;
gboolean thread_running = FALSE;

// Константы
#define pci_addr_range  0x02000000
#define image_verion_addr 0x00020000
#define gpio_sel_addr 0x00130000
#define gpio_in 0x0
#define gpio_out 0x8

// Функция для обновления статусной строки
void update_status_bar(const gchar *message) {
    gtk_statusbar_push(GTK_STATUSBAR(status_bar), 0, message);
}

// Функция для чтения значения из регистра FPGA
uint32_t read_register(off_t offset) {
    if (!is_connected || pcie_base == NULL) {
        return 0;
    }
    
    void *virt_addr = (char*)pcie_base + offset;
    return *(volatile uint32_t*)virt_addr;
}

// Функция для записи значения в регистр FPGA
void write_register(off_t offset, uint32_t value) {
    if (!is_connected || pcie_base == NULL) {
        return;
    }
    
    void *virt_addr = (char*)pcie_base + offset;
    *(volatile uint32_t*)virt_addr = value;
}

// Функция для обновления информации о версиях IP-ядер
void update_versions() {
    char buffer[64];
    uint32_t read_result;
    
    // Версия образа FPGA
    read_result = read_register(image_verion_addr);
    snprintf(buffer, sizeof(buffer), "0x%X", read_result);
    gtk_label_set_text(GTK_LABEL(label_fpga_version), buffer);
    
    // Версия ядра Clock IP Core
    read_result = read_register(NTL_CLK_REGSET_BASE + NTL_CLK_CLKVERSION_REG);
    snprintf(buffer, sizeof(buffer), "0x%X", read_result);
    gtk_label_set_text(GTK_LABEL(label_clock_version), buffer);
    
    // Версия ядра Signal TS IP Core (1)
    read_result = read_register(NTL_STS1_REGSET_BASE + NTL_STS_VERSION_REG);
    snprintf(buffer, sizeof(buffer), "0x%X", read_result);
    gtk_label_set_text(GTK_LABEL(label_signal_ts1_version), buffer);
    
    // Версия ядра Signal TS IP Core (2)
    read_result = read_register(NTL_STS2_REGSET_BASE + NTL_STS_VERSION_REG);
    snprintf(buffer, sizeof(buffer), "0x%X", read_result);
    gtk_label_set_text(GTK_LABEL(label_signal_ts2_version), buffer);
    
    // Версия ядра PPS Master IP Core
    read_result = read_register(NTL_PPSM_REGSET_BASE + NTL_PPSM_VERSION_REG);
    snprintf(buffer, sizeof(buffer), "0x%X", read_result);
    gtk_label_set_text(GTK_LABEL(label_pps_master_version), buffer);
    
    // Версия ядра PPS Slave IP Core
    read_result = read_register(NTL_PPSS_REGSET_BASE + NTL_PPSS_VERSION_REG);
    snprintf(buffer, sizeof(buffer), "0x%X", read_result);
    gtk_label_set_text(GTK_LABEL(label_pps_slave_version), buffer);
    
    // Версия ядра TOD Slave IP Core
    read_result = read_register(NTL_TOD_REGSET_BASE + NTL_TOD_VERSION_REG);
    snprintf(buffer, sizeof(buffer), "0x%X", read_result);
    gtk_label_set_text(GTK_LABEL(label_tod_slave_version), buffer);
}

// Функция для обновления статуса часов
void update_clock_status() {
    uint32_t read_result;
    
    // Проверка включены ли часы
    read_result = read_register(NTL_CLK_REGSET_BASE + NTL_CLK_CLKCONTROL_REG);
    if (read_result & NTL_CLK_CONTROL_ENABLE_BIT) {
        gtk_label_set_text(GTK_LABEL(label_clock_status), "Включены");
    } else {
        gtk_label_set_text(GTK_LABEL(label_clock_status), "Выключены");
    }
    
    // Определение источника тактирования
    read_result = read_register(NTL_CLK_REGSET_BASE + NTL_CLK_CLKSELECT_REG);
    switch ((read_result >> 16) & 0xff) {
        case NTL_CLK_SELECT_NONE:
            gtk_label_set_text(GTK_LABEL(label_clock_source), "NONE");
            break;
        case NTL_CLK_SELECT_TOD:
            gtk_label_set_text(GTK_LABEL(label_clock_source), "TOD");
            break;
        case NTL_CLK_SELECT_IRIG:
            gtk_label_set_text(GTK_LABEL(label_clock_source), "IRIG");
            break;
        case NTL_CLK_SELECT_PPS:
            gtk_label_set_text(GTK_LABEL(label_clock_source), "PPS");
            break;
        case NTL_CLK_SELECT_PTP:
            gtk_label_set_text(GTK_LABEL(label_clock_source), "PTP");
            break;
        case NTL_CLK_SELECT_RTC:
            gtk_label_set_text(GTK_LABEL(label_clock_source), "RTC");
            break;
        case NTL_CLK_SELECT_DCF:
            gtk_label_set_text(GTK_LABEL(label_clock_source), "DCF");
            break;
        case NTL_CLK_SELECT_REGS:
            gtk_label_set_text(GTK_LABEL(label_clock_source), "REGS");
            break;
        case NTL_CLK_SELECT_EXT:
            gtk_label_set_text(GTK_LABEL(label_clock_source), "EXT");
            break;
        default:
            gtk_label_set_text(GTK_LABEL(label_clock_source), "Неизвестно");
            break;
    }
}

// Функция для обновления состояния GPIO
void update_gpio_status() {
    uint32_t read_result;
    char buffer[64];
    
    // Чтение состояния GPIO
    read_result = read_register(gpio_sel_addr + gpio_in);
    snprintf(buffer, sizeof(buffer), "0x%X", read_result);
    gtk_label_set_text(GTK_LABEL(label_gpio_status), buffer);
    
    // Обновление индикаторов GPIO
    for (int i = 0; i < 8; i++) {
        if (read_result & (1 << i)) {
            gtk_widget_set_name(gpio_indicators[i], "indicator-on");
        } else {
            gtk_widget_set_name(gpio_indicators[i], "indicator-off");
        }
    }
}

// Функция для обновления ширины импульса PPS
void update_pps_pulse_width() {
    uint32_t read_result;
    char buffer[64];
    
    // Чтение ширины импульса PPS
    read_result = read_register(NTL_PPSS_REGSET_BASE + NTL_PPSS_PULSEWIDTH_REG);
    snprintf(buffer, sizeof(buffer), "%d", read_result);
    gtk_label_set_text(GTK_LABEL(label_pps_pulse_width), buffer);
}

// Функция для обновления всех данных
void update_all_data() {
    if (!is_connected) {
        return;
    }
    
    update_versions();
    update_clock_status();
    update_gpio_status();
    update_pps_pulse_width();
}

// Функция потока мониторинга
void* monitor_thread_func(void *data) {
    thread_running = TRUE;
    
    while (is_monitoring && thread_running) {
        // Обновление данных в основном потоке
        gdk_threads_add_idle((GSourceFunc)update_all_data, NULL);
        
        // Пауза 1 секунда
        sleep(1);
    }
    
    thread_running = FALSE;
    return NULL;
}

// Обработчик нажатия кнопки "Подключиться"
void on_connect_clicked(GtkWidget *widget, gpointer data) {
    const gchar *addr_text = gtk_entry_get_text(GTK_ENTRY(entry_pcie_addr));
    
    // Проверка формата адреса
    if (strlen(addr_text) != 10 || strncmp(addr_text, "0x", 2) != 0) {
        update_status_bar("Ошибка: Неверный формат адреса PCIe. Используйте формат 0xA0000000");
        return;
    }
    
    // Преобразование адреса
    pcie_addr = (uint32_t)strtol(addr_text, NULL, 0);
    
    // Открытие /dev/mem
    if ((fd = open("/dev/mem", O_RDWR | O_SYNC)) == -1) {
        update_status_bar("Ошибка: Не удалось открыть /dev/mem. Запустите программу с правами root.");
        return;
    }
    
    // Отображение памяти
    unsigned page_size = getpagesize();
    mapped_size = pci_addr_range;
    
    pcie_base = mmap(0, mapped_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, pcie_addr & ~(off_t)(page_size - 1));
    
    if (pcie_base == MAP_FAILED) {
        update_status_bar("Ошибка: Не удалось отобразить память FPGA.");
        close(fd);
        fd = -1;
        pcie_base = NULL;
        return;
    }
    
    // Обновление состояния
    is_connected = TRUE;
    gtk_widget_set_sensitive(button_connect, FALSE);
    gtk_widget_set_sensitive(button_disconnect, TRUE);
    gtk_widget_set_sensitive(button_start_stop, TRUE);
    
    // Обновление данных
    update_all_data();
    
    // Обновление статусной строки
    char buffer[128];
    snprintf(buffer, sizeof(buffer), "Подключено к FPGA по адресу %s", addr_text);
    update_status_bar(buffer);
}

// Обработчик нажатия кнопки "Отключиться"
void on_disconnect_clicked(GtkWidget *widget, gpointer data) {
    // Остановка мониторинга
    if (is_monitoring) {
        is_monitoring = FALSE;
        if (thread_running) {
            pthread_join(monitor_thread, NULL);
        }
        gtk_button_set_label(GTK_BUTTON(button_start_stop), "Запустить мониторинг");
    }
    
    // Освобождение ресурсов
    if (pcie_base != NULL && pcie_base != MAP_FAILED) {
        munmap(pcie_base, mapped_size);
        pcie_base = NULL;
    }
    
    if (fd != -1) {
        close(fd);
        fd = -1;
    }
    
    // Обновление состояния
    is_connected = FALSE;
    gtk_widget_set_sensitive(button_connect, TRUE);
    gtk_widget_set_sensitive(button_disconnect, FALSE);
    gtk_widget_set_sensitive(button_start_stop, FALSE);
    
    // Очистка меток
    gtk_label_set_text(GTK_LABEL(label_fpga_version), "");
    gtk_label_set_text(GTK_LABEL(label_clock_version), "");
    gtk_label_set_text(GTK_LABEL(label_signal_ts1_version), "");
    gtk_label_set_text(GTK_LABEL(label_signal_ts2_version), "");
    gtk_label_set_text(GTK_LABEL(label_pps_master_version), "");
    gtk_label_set_text(GTK_LABEL(label_pps_slave_version), "");
    gtk_label_set_text(GTK_LABEL(label_tod_slave_version), "");
    gtk_label_set_text(GTK_LABEL(label_clock_status), "");
    gtk_label_set_text(GTK_LABEL(label_clock_source), "");
    gtk_label_set_text(GTK_LABEL(label_gpio_status), "");
    gtk_label_set_text(GTK_LABEL(label_pps_pulse_width), "");
    
    // Сброс индикаторов GPIO
    for (int i = 0; i < 8; i++) {
        gtk_widget_set_name(gpio_indicators[i], "indicator-off");
    }
    
    // Обновление статусной строки
    update_status_bar("Отключено от FPGA");
}

// Обработчик нажатия кнопки "Запустить/Остановить мониторинг"
void on_start_stop_clicked(GtkWidget *widget, gpointer data) {
    if (!is_connected) {
        return;
    }
    
    if (is_monitoring) {
        // Остановка мониторинга
        is_monitoring = FALSE;
        if (thread_running) {
            pthread_join(monitor_thread, NULL);
        }
        gtk_button_set_label(GTK_BUTTON(button_start_stop), "Запустить мониторинг");
        update_status_bar("Мониторинг остановлен");
    } else {
        // Запуск мониторинга
        is_monitoring = TRUE;
        pthread_create(&monitor_thread, NULL, monitor_thread_func, NULL);
        gtk_button_set_label(GTK_BUTTON(button_start_stop), "Остановить мониторинг");
        update_status_bar("Мониторинг запущен");
    }
}

// Обработчик закрытия окна
gboolean on_window_delete_event(GtkWidget *widget, GdkEvent *event, gpointer data) {
    // Остановка мониторинга
    if (is_monitoring) {
        is_monitoring = FALSE;
        if (thread_running) {
            pthread_join(monitor_thread, NULL);
        }
    }
    
    // Освобождение ресурсов
    if (pcie_base != NULL && pcie_base != MAP_FAILED) {
        munmap(pcie_base, mapped_size);
    }
    
    if (fd != -1) {
        close(fd);
    }
    
    return FALSE;
}

// Функция для создания индикатора GPIO
GtkWidget* create_gpio_indicator() {
    GtkWidget *indicator = gtk_drawing_area_new();
    gtk_widget_set_size_request(indicator, 20, 20);
    gtk_widget_set_name(indicator, "indicator-off");
    
    return indicator;
}

// Функция для создания CSS стилей
void load_css() {
    GtkCssProvider *provider = gtk_css_provider_new();
    GdkDisplay *display = gdk_display_get_default();
    GdkScreen *screen = gdk_display_get_default_screen(display);
    
    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    
    const gchar *css =
        ".indicator-on { background-color: #00FF00; border-radius: 10px; }"
        ".indicator-off { background-color: #FF0000; border-radius: 10px; }";
    
    gtk_css_provider_load_from_data(provider, css, -1, NULL);
    g_object_unref(provider);
}

int main(int argc, char **argv) {
    // Инициализация GTK
    gtk_init(&argc, &argv);
    
    // Загрузка CSS стилей
    load_css();
    
    // Создание главного окна
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "TestApp GUI");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(window, "delete-event", G_CALLBACK(on_window_delete_event), NULL);
    
    // Создание основного контейнера
    GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), main_box);
    
    // Создание верхней панели
    GtkWidget *top_panel = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(main_box), top_panel, FALSE, FALSE, 0);
    
    // Добавление элементов в верхнюю панель
    GtkWidget *label_pcie_addr = gtk_label_new("Базовый адрес PCIe:");
    gtk_box_pack_start(GTK_BOX(top_panel), label_pcie_addr, FALSE, FALSE, 0);
    
    entry_pcie_addr = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(entry_pcie_addr), "0xA0000000");
    gtk_box_pack_start(GTK_BOX(top_panel), entry_pcie_addr, TRUE, TRUE, 0);
    
    button_connect = gtk_button_new_with_label("Подключиться");
    g_signal_connect(button_connect, "clicked", G_CALLBACK(on_connect_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(top_panel), button_connect, FALSE, FALSE, 0);
    
    button_disconnect = gtk_button_new_with_label("Отключиться");
    g_signal_connect(button_disconnect, "clicked", G_CALLBACK(on_disconnect_clicked), NULL);
    gtk_widget_set_sensitive(button_disconnect, FALSE);
    gtk_box_pack_start(GTK_BOX(top_panel), button_disconnect, FALSE, FALSE, 0);
    
    // Создание контейнера для основного содержимого
    GtkWidget *content_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_pack_start(GTK_BOX(main_box), content_box, TRUE, TRUE, 0);
    
    // Создание левой панели (версии IP-ядер)
    GtkWidget *left_panel = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_pack_start(GTK_BOX(content_box), left_panel, TRUE, TRUE, 0);
    
    // Добавление рамки и заголовка для левой панели
    GtkWidget *left_frame = gtk_frame_new("Версии IP-ядер");
    gtk_container_add(GTK_CONTAINER(left_frame), left_panel);
    gtk_box_pack_start(GTK_BOX(content_box), left_frame, TRUE, TRUE, 0);
    
    // Добавление элементов в левую панель
    GtkWidget *grid_versions = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid_versions), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid_versions), 10);
    gtk_box_pack_start(GTK_BOX(left_panel), grid_versions, FALSE, FALSE, 0);
    
    // Метки для версий IP-ядер
    GtkWidget *label_fpga = gtk_label_new("Версия образа FPGA:");
    gtk_grid_attach(GTK_GRID(grid_versions), label_fpga, 0, 0, 1, 1);
    label_fpga_version = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid_versions), label_fpga_version, 1, 0, 1, 1);
    
    GtkWidget *label_clock = gtk_label_new("Clock IP Core:");
    gtk_grid_attach(GTK_GRID(grid_versions), label_clock, 0, 1, 1, 1);
    label_clock_version = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid_versions), label_clock_version, 1, 1, 1, 1);
    
    GtkWidget *label_signal_ts1 = gtk_label_new("Signal TS IP Core (1):");
    gtk_grid_attach(GTK_GRID(grid_versions), label_signal_ts1, 0, 2, 1, 1);
    label_signal_ts1_version = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid_versions), label_signal_ts1_version, 1, 2, 1, 1);
    
    GtkWidget *label_signal_ts2 = gtk_label_new("Signal TS IP Core (2):");
    gtk_grid_attach(GTK_GRID(grid_versions), label_signal_ts2, 0, 3, 1, 1);
    label_signal_ts2_version = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid_versions), label_signal_ts2_version, 1, 3, 1, 1);
    
    GtkWidget *label_pps_master = gtk_label_new("PPS Master IP Core:");
    gtk_grid_attach(GTK_GRID(grid_versions), label_pps_master, 0, 4, 1, 1);
    label_pps_master_version = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid_versions), label_pps_master_version, 1, 4, 1, 1);
    
    GtkWidget *label_pps_slave = gtk_label_new("PPS Slave IP Core:");
    gtk_grid_attach(GTK_GRID(grid_versions), label_pps_slave, 0, 5, 1, 1);
    label_pps_slave_version = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid_versions), label_pps_slave_version, 1, 5, 1, 1);
    
    GtkWidget *label_tod_slave = gtk_label_new("TOD Slave IP Core:");
    gtk_grid_attach(GTK_GRID(grid_versions), label_tod_slave, 0, 6, 1, 1);
    label_tod_slave_version = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid_versions), label_tod_slave_version, 1, 6, 1, 1);
    
    // Создание правой панели (статус)
    GtkWidget *right_panel = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    
    // Добавление рамки и заголовка для правой панели
    GtkWidget *right_frame = gtk_frame_new("Статус");
    gtk_container_add(GTK_CONTAINER(right_frame), right_panel);
    gtk_box_pack_start(GTK_BOX(content_box), right_frame, TRUE, TRUE, 0);
    
    // Добавление элементов в правую панель
    GtkWidget *grid_status = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid_status), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid_status), 10);
    gtk_box_pack_start(GTK_BOX(right_panel), grid_status, FALSE, FALSE, 0);
    
    // Метки для статуса
    GtkWidget *label_clock_status_title = gtk_label_new("Статус часов:");
    gtk_grid_attach(GTK_GRID(grid_status), label_clock_status_title, 0, 0, 1, 1);
    label_clock_status = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid_status), label_clock_status, 1, 0, 1, 1);
    
    GtkWidget *label_clock_source_title = gtk_label_new("Источник тактирования:");
    gtk_grid_attach(GTK_GRID(grid_status), label_clock_source_title, 0, 1, 1, 1);
    label_clock_source = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid_status), label_clock_source, 1, 1, 1, 1);
    
    GtkWidget *label_gpio_status_title = gtk_label_new("Состояние GPIO:");
    gtk_grid_attach(GTK_GRID(grid_status), label_gpio_status_title, 0, 2, 1, 1);
    label_gpio_status = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid_status), label_gpio_status, 1, 2, 1, 1);
    
    GtkWidget *label_pps_pulse_width_title = gtk_label_new("Ширина импульса PPS:");
    gtk_grid_attach(GTK_GRID(grid_status), label_pps_pulse_width_title, 0, 3, 1, 1);
    label_pps_pulse_width = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid_status), label_pps_pulse_width, 1, 3, 1, 1);
    
    // Добавление индикаторов GPIO
    GtkWidget *gpio_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_grid_attach(GTK_GRID(grid_status), gtk_label_new("Индикаторы GPIO:"), 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid_status), gpio_box, 1, 4, 1, 1);
    
    for (int i = 0; i < 8; i++) {
        gpio_indicators[i] = create_gpio_indicator();
        gtk_box_pack_start(GTK_BOX(gpio_box), gpio_indicators[i], FALSE, FALSE, 0);
    }
    
    // Создание нижней панели
    GtkWidget *bottom_panel = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(main_box), bottom_panel, FALSE, FALSE, 0);
    
    // Добавление элементов в нижнюю панель
    button_start_stop = gtk_button_new_with_label("Запустить мониторинг");
    g_signal_connect(button_start_stop, "clicked", G_CALLBACK(on_start_stop_clicked), NULL);
    gtk_widget_set_sensitive(button_start_stop, FALSE);
    gtk_box_pack_start(GTK_BOX(bottom_panel), button_start_stop, FALSE, FALSE, 0);
    
    // Создание статусной строки
    status_bar = gtk_statusbar_new();
    gtk_box_pack_start(GTK_BOX(main_box), status_bar, FALSE, FALSE, 0);
    update_status_bar("Готово к работе");
    
    // Отображение всех виджетов
    gtk_widget_show_all(window);
    
    // Запуск главного цикла GTK
    gtk_main();
    
    return 0;
}

