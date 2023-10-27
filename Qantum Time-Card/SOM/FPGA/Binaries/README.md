# Бинарные файлы модуля SOM

- **200T** Бинарные файлы FPGA для модуля SOM с FPGA Artix7 200T (AC7200)
- **AX7103_Baseboard** Бинарные файлы FPGA  для базовой платы AX7103 (больше не поддерживаются)
- **Debug** Бинарные файлы FPGA TimeCard для особых случаев отладки (больше не поддерживаются)
- **FirmwareUpdateTest** Бинарные файлы FPGA для тестирования обновления прошивки

## В этой папке находятся битовые потоки для модуля SOM. ## 
* TimeCard.bit для записи в FPGA (временная конфигурация)
* Factory_TimeCard.bin для загрузки SPI Flash через JTAG (Золотое изображение + Обновление)
* TimeCard.bin для обновления SPI Flash через SPI, начиная с адреса 0x00400000 (только обновление)
* TimeCard_Gotham.bin фактически идентичен TimeCard.bin, но файл содержит дополнительную информацию в заголовке ([См. инструмент tft]


## Обновление прошивки
```
$ dmesg | grep ptp_ocp | head -1
[   21.527678] ptp_ocp 0000:11:00.0: enabling device (0140 -> 0142)
$ cp TimeCard.bin /lib/firmware
$ devlink dev flash pci/0000:11:00.0 file TimeCard.bin
```
