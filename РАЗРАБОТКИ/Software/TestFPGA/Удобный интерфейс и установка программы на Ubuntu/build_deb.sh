#!/bin/bash

# Скрипт для сборки deb-пакета TestApp GUI

echo "Сборка deb-пакета TestApp GUI..."

# Проверка наличия исполняемого файла
if [ ! -f "./testapp_gui" ]; then
    echo "Ошибка: исполняемый файл testapp_gui не найден." 1>&2
    echo "Запустите build.sh для компиляции программы." 1>&2
    exit 1
fi

# Создание структуры каталогов для deb-пакета
mkdir -p debian/DEBIAN
mkdir -p debian/usr/bin
mkdir -p debian/usr/share/applications
mkdir -p debian/usr/share/pixmaps
mkdir -p debian/usr/share/polkit-1/actions

# Создание файла control
cat > debian/DEBIAN/control << EOF
Package: testapp-gui
Version: 1.0.0
Section: utils
Priority: optional
Architecture: amd64
Depends: libgtk-3-0, policykit-1
Maintainer: TestApp Team <testapp@example.com>
Description: Графический интерфейс для TestApp
 TestApp GUI - это графический интерфейс для программы TestApp,
 которая взаимодействует с FPGA через PCI Express (PCIe) и
 предоставляет информацию о версиях IP-ядер, статусе часов и
 PPS (Pulse Per Second), а также позволяет отслеживать текущие
 состояния сигналов.
EOF

# Создание скрипта postinst
cat > debian/DEBIAN/postinst << EOF
#!/bin/sh
# postinst script for testapp-gui

set -e

# Обновление кэша иконок
if [ -x /usr/bin/update-icon-caches ]; then
    update-icon-caches /usr/share/pixmaps
fi

# Обновление кэша приложений
if [ -x /usr/bin/update-desktop-database ]; then
    update-desktop-database -q
fi

exit 0
EOF

# Создание скрипта prerm
cat > debian/DEBIAN/prerm << EOF
#!/bin/sh
# prerm script for testapp-gui

set -e

exit 0
EOF

# Установка прав на скрипты
chmod 755 debian/DEBIAN/postinst debian/DEBIAN/prerm

# Копирование файлов
cp testapp_gui debian/usr/bin/
cp testapp_gui.desktop debian/usr/share/applications/
cp testapp_gui.png debian/usr/share/pixmaps/
cp testapp_gui.policy debian/usr/share/polkit-1/actions/org.testapp.gui.policy

# Сборка пакета
dpkg-deb --build debian testapp-gui_1.0.0_amd64.deb

# Проверка результата
if [ $? -eq 0 ]; then
    echo "Сборка deb-пакета успешно завершена."
    echo "Пакет: $(pwd)/testapp-gui_1.0.0_amd64.deb"
else
    echo "Ошибка при сборке deb-пакета." 1>&2
    exit 1
fi

