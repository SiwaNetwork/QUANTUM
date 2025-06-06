#!/bin/bash

# Скрипт для установки TestApp GUI в систему
# Требуются права root

# Проверка прав root
if [ "$(id -u)" != "0" ]; then
   echo "Этот скрипт должен быть запущен с правами root" 1>&2
   echo "Используйте: sudo $0" 1>&2
   exit 1
fi

echo "Установка TestApp GUI..."

# Проверка наличия исполняемого файла
if [ ! -f "./testapp_gui" ]; then
    echo "Ошибка: исполняемый файл testapp_gui не найден." 1>&2
    echo "Запустите build.sh для компиляции программы." 1>&2
    exit 1
fi

# Установка исполняемого файла
install -m 755 testapp_gui /usr/bin/

# Установка .desktop файла
install -m 644 testapp_gui.desktop /usr/share/applications/

# Установка иконки
install -m 644 testapp_gui.png /usr/share/pixmaps/

# Установка файла политики
install -m 644 testapp_gui.policy /usr/share/polkit-1/actions/org.testapp.gui.policy

echo "Установка TestApp GUI завершена."
echo "Теперь вы можете запустить программу из меню приложений или командой 'testapp_gui'."

