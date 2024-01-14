System on Module (SOM)

FPGA (Field-Programmable Gate Array) bitstream можно настроить на различные параметры. В настоящее время он основан на [модуле часов NetTimeLogic](https://www.nettimelogic.com/clock-products.php). <br />


В [папке Документы]находятся все соответствующие документы о встроенных IP-ядрах (например, описания регистров). <br />

## FPGA начинает работу с статической конфигурацией, имеющей следующие параметры: ##
* PPS (включая TOD) используется в качестве входа для коррекции часов
* Обнаружение импульсов PPS Slave по фронту подъема
* Задержка кабеля PPS Slave равна 0
* Скорость передачи данных UART PPS Slave равна 115200
* Полярность UART PPS Slave по умолчанию
* PPS Slave в режиме UBX, все сообщения GNSS отключены
* Полярность импульсов PPS Master по фронту подъема
* Задержка кабеля PPS Master равна 0
* Ширина импульсов PPS Master составляет 100 мс
* Включены часы, PPS Slave, TOD Slave и PPS Master
* Все модули метки времени отключены
* IRIG Slave/Master отключены
* DCF Slave/Master отключены
* TOD/NMEA Master отключены

## В папке Binaries находятся битовые потоки для модуля SOM. ## 
* TimeCard.bit для записи в FPGA (временная конфигурация)
* Factory_TimeCard.bin для загрузки SPI Flash через JTAG (Золотое изображение + Обновление)
* TimeCard.bin для обновления SPI Flash через SPI, начиная с адреса 0x00400000 (только обновление)

Версия для AX7103 больше не поддерживаться.

## Обновление прошивки
```
$ dmesg | grep ptp_ocp | head -1
[   21.527678] ptp_ocp 0000:11:00.0: enabling device (0140 -> 0142)
$ cp TimeCard.bin /lib/firmware
$ devlink dev flash pci/0000:11:00.0 file TimeCard.bin
```
