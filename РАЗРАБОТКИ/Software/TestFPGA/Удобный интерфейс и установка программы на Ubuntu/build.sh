#!/bin/bash

# Скрипт для компиляции TestApp GUI

echo "Компиляция TestApp GUI..."

# Проверка наличия необходимых инструментов
if ! command -v gcc &> /dev/null; then
    echo "Ошибка: gcc не установлен. Запустите install_dependencies.sh" 1>&2
    exit 1
fi

if ! command -v make &> /dev/null; then
    echo "Ошибка: make не установлен. Запустите install_dependencies.sh" 1>&2
    exit 1
fi

if ! command -v pkg-config &> /dev/null; then
    echo "Ошибка: pkg-config не установлен. Запустите install_dependencies.sh" 1>&2
    exit 1
fi

# Проверка наличия библиотеки GTK+
if ! pkg-config --exists gtk+-3.0; then
    echo "Ошибка: библиотека GTK+ 3 не установлена. Запустите install_dependencies.sh" 1>&2
    exit 1
fi

# Компиляция
make clean
make

# Проверка успешности компиляции
if [ $? -eq 0 ]; then
    echo "Компиляция успешно завершена."
    echo "Исполняемый файл: $(pwd)/testapp_gui"
else
    echo "Ошибка при компиляции." 1>&2
    exit 1
fi

