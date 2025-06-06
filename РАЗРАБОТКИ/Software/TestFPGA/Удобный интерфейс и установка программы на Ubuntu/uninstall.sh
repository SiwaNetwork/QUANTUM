#!/bin/bash

# Скрипт для удаления TestApp GUI из системы
# Требуются права root

# Проверка прав root
if [ "$(id -u)" != "0" ]; then
   echo "Этот скрипт должен быть запущен с правами root" 1>&2
   echo "Используйте: sudo $0" 1>&2
   exit 1
fi

echo "Удаление TestApp GUI..."

# Удаление исполняемого файла
rm -f /usr/bin/testapp_gui

# Удаление .desktop файла
rm -f /usr/share/applications/testapp_gui.desktop

# Удаление иконки
rm -f /usr/share/pixmaps/testapp_gui.png

# Удаление файла политики
rm -f /usr/share/polkit-1/actions/org.testapp.gui.policy

echo "Удаление TestApp GUI завершено."

