
#  НЕ ПОДДЕРЖИВАЮТСЯ двоичные файлы специальных версий Bitstream для отладки и т.д.
## TimeCardDoublePPS.bit
* ANT4 --> Выход PPS от PPS Master
* ANT3 --> TimePule от модуля GPS (который идет на PPS Slave)
## TimeCardTopUSBUARTGPS.bit
USB UART (используется для UCM) непосредственно отображается на UART модуля GPS.
Прошивка этой версии позволяет подключаться, например, через u-center. С этим bitstream UCM использовать нельзя.