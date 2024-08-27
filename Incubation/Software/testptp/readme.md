Вот testptp для настройки выводов PPS на сетевой карте

чтобы получить testptp независимо, выполните следующие команды

cd~
mkdir testptp
cd testptp

Используйте следующую команду для компиляции:

make
или используйте полную команду

gcc -Wall -lrt testptp.c -o testptp
Если вы получаете ошибку errno.h, вам следует установить libc6-dev.

Для использования при установке:

sudo make install
или просто используйте

sudo mv testptp /usr/bin/
Чтобы включить вывод PPS для eth0, используйте следующую команду:

ptp_dev=`ethtool -T eth0 | awk '/PTP Hardware Clock:/ {print $4}'` && testptp -d /dev/ptp$ptp_dev -L 0,1

Чтобы включить PPS в для eth0, используйте следующую команду:

ptp_dev=`ethtool -T eth0 | awk '/PTP Hardware Clock:/ {print $4}'` && testptp -d /dev/ptp$ptp_dev -e -1
