// Функция для чтения конфигурации выбранного ядра
void read_core_config(int core_index) {
    if (!is_connected || core_index < 0 || core_index >= NUM_CORES) {
        return;
    }
    
    CoreInfo *core = &cores[core_index];
    char buffer[4096] = {0};
    char line[256];
    uint32_t read_result;
    
    // Добавляем заголовок
    snprintf(buffer, sizeof(buffer), "Конфигурация ядра: %s\n", core->name);
    strcat(buffer, "Адрес: 0x");
    sprintf(line, "%08X\n", core->base_addr);
    strcat(buffer, line);
    strcat(buffer, "Версия: 0x");
    read_result = read_register(core->base_addr + core->version_reg);
    sprintf(line, "%08X\n\n", read_result);
    strcat(buffer, line);
    
    // Читаем регистры
    strcat(buffer, "Регистры:\n");
    for (uint32_t i = 0; i < core->num_regs; i++) {
        uint32_t reg_addr = core->base_addr + (i * 4);
        read_result = read_register(reg_addr);
        sprintf(line, "0x%08X: 0x%08X\n", reg_addr, read_result);
        strcat(buffer, line);
    }
    
    // Обновляем текстовое поле
    gtk_text_buffer_set_text(text_buffer_config, buffer, -1);
}

// Обработчик выбора ядра в выпадающем списке
void on_core_selected(GtkComboBox *widget, gpointer data) {
    int core_index = gtk_combo_box_get_active(GTK_COMBO_BOX(combo_core));
    if (core_index >= 0 && is_connected) {
        read_core_config(core_index);
    }
}

// Обработчик нажатия кнопки "Прочитать конфигурацию"
void on_read_config_clicked(GtkWidget *widget, gpointer data) {
    int core_index = gtk_combo_box_get_active(GTK_COMBO_BOX(combo_core));
    if (core_index >= 0 && is_connected) {
        read_core_config(core_index);
        update_status_bar("Конфигурация ядра прочитана");
    } else {
        update_status_bar("Выберите ядро и подключитесь к FPGA");
    }
}

// Обработчик нажатия кнопки "Записать конфигурацию"
void on_write_config_clicked(GtkWidget *widget, gpointer data) {
    // В будущей версии здесь будет реализована запись конфигурации
    update_status_bar("Запись конфигурации пока не реализована");
}

// Функция для заполнения выпадающего списка ядер
void populate_core_combo() {
    for (int i = 0; i < NUM_CORES; i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_core), cores[i].name);
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(combo_core), 0);
}

