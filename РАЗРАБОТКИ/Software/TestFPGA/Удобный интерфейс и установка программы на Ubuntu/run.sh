#!/bin/bash

# Скрипт для запуска TestApp GUI

# Проверка наличия исполняемого файла
if [ ! -f "./testapp_gui" ]; then
    echo "Ошибка: исполняемый файл testapp_gui не найден." 1>&2
    echo "Запустите build.sh для компиляции программы." 1>&2
    exit 1
fi

# Проверка прав root
if [ "$(id -u)" != "0" ]; then
    echo "Для доступа к /dev/mem требуются права root."
    echo "Запуск через pkexec..."
    pkexec "$(pwd)/testapp_gui"
else
    # Запуск программы
    ./testapp_gui
fi

