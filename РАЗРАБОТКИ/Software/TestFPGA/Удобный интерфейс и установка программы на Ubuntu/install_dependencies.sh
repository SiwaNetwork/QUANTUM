#!/bin/bash

# Скрипт для установки зависимостей TestApp GUI
# Требуются права root

# Проверка прав root
if [ "$(id -u)" != "0" ]; then
   echo "Этот скрипт должен быть запущен с правами root" 1>&2
   echo "Используйте: sudo $0" 1>&2
   exit 1
fi

echo "Установка зависимостей для TestApp GUI..."

# Обновление списка пакетов
apt-get update

# Установка необходимых пакетов для сборки
apt-get install -y gcc make pkg-config libgtk-3-dev

# Установка необходимых пакетов для запуска
apt-get install -y libgtk-3-0 policykit-1

echo "Установка зависимостей завершена."

