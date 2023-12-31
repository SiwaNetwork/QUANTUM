Для сохранения спецификации в формате PDF, выполните следующие действия:

1. Выделите текст ниже (включая изображения).
2. Щелкните правой кнопкой мыши.
3. Выберите "Печать" (Print).
4. Выберите "Сохранить как PDF" (Save as PDF).


# Временной сервер
#### Спецификация, версия № 1.0
Временной сервер (TS) - это масштабируемая  архитектура, которая может быть развернута в центрах обработки данных или на периферийных устройствах.


## Содержание
1. [Сокращения](#Сокращения)
2. [Общее](#Общее)
3. [Архитектура высокого уровня](#Архитектура-высокого-уровня)
   1. [Обязанности и требования](#Обязанности-и-требования)
      1. [COTS-сервер](#COTS-сервер)
      1. [Сетевая сетевая карта (NIC)](#Сетевая-сетевая-карта-(NIC))
      1. [Временная карта (Time Card)](#Временная-карта-(Time-Card))
4. [Подробная архитектура](#Подробная-архитектура)
   1. [COTS-сервер](#COTS-сервер-1)
      1. [Аппаратное обеспечение](#Аппаратное-обеспечение)
      1. [Программное обеспечение](#Программное-обеспечение)
   1. [Сетевая сетевая карта (NIC)](#Сетевая-сетевая-карта-(NIC)-1)
      1. [Форм-фактор](#Форм-фактор)
      1. [Интерфейс PCIe](#Интерфейс-PCIe)
      1. [Сетевые порты](#Сетевые-порты)
      1. [Аппаратные метки времени](#Аппаратные-метки-времени)
      1. [PPS вход (вывод)](#PPS-вход-(вывод))
   1. [Временная карта (Qantum PCIe)](#Временная-карта-(PCI)-1)


## Сокращения
Сокращение | Описание
------------ | -------------
AC | Атомные часы (Atomic Clock)
COTS | Готовое к использованию с оборудованием (Commodity off-the-shelf)
DC | Центр обработки данных (Datacenter)
GNSS | Глобальная навигационная спутниковая система (Global Navigation Satellite System)
HW | Аппаратное обеспечение (Hardware)
NIC | Сетевая сетевая карта (Network Interface Card)
NTP | Сетевой протокол времени (Network Time Protocol)
OCXO | Кварцевый-термокомпенсированный осциллятор (Controlled Oscillator)
PHC | Аппаратные часы PTP (PTP Hardware Clock)
PPS | Импульсы в секунду (Pulse-Per-Second)
PTM | Точные измерения времени (Precision Time Measurements)
PTP | Протокол точного времени (Precision Time Protocol)
SW | Программное обеспечение (Software)
TAP | Проект временного устройства (Time Appliance Project)
TCXO | Температуроустойчивый осциллятор с компенсацией температуры (Temperature-compensated Oscillator)
ToD | Время дня (Time of Day)
TS | Метка времени (Timestamp)
XO | Осциллятор (Oscillator)

Таблица 1. Сокращения

# Общее
Qantum PCIe нацелен на упрощение добавления синхронизации времени в качестве сервиса в центры обработки данных. 
Сервис синхронизации времени базируется на технологии синхронизации, и на данный момент мы используем PTP (IEEE 1588) с некоторыми дополнениями и NTP.

Архитектура

 PTP масштабируется и определяет источник времени сущности, называемой **часами времени сервера** (или Stratum 1 в терминах NTP). Открытый временной сервер распространяет время по всей сети и обычно получает свое время из внешнего источника (сигнала GNSS).

Существующие реализации временных серверов имеют несколько недостатков, которые мы хотим учесть:

* Это аппаратное оборудование, обычно ориентированное на другой рынок, чем центры обработки данных.
* Они предоставляют нестандартные и несовместимые интерфейсы и наборы функций программного обеспечения.
* Циклы разработки и усилия, необходимые для добавления новых функций, являются долгими и дорогостоящими.
* Точность и стабильность не соответствуют требованиям центров обработки данных.

# Архитектура высокого уровня
В целом, сервера делятся на 3 вида:

1. COTS-сервер
2. Сетевая карта (NIC)
3. Временная карта (Time Card)

<a id="Рисунок-1">![Диаграмма системы открытого временного сервера](/Time-Card/images/overall.png)</a>
<p align="center">Рисунок 1. Диаграмма системы открытого временного сервера</p>

Философия, лежащая в основе этой разработки:

* Временная карта будет самой маленькой  платой аппаратного оборудования, которая предоставит входной сигнал GNSS и стабильный частотный вход. Изолирование этих функций на временной карте позволит OTS выбирать подходящую временную карту для своих потребностей (точность, стабильность, стоимость и т. д.) и оставаться при том же программном обеспечении, интерфейсе и архитектуре.

Основная идея заключается в том, что временная карта подключается через интерфейс PCIe к серверу и предоставляет время суток (ToD) через интерфейс `/dev/ptpX`. С использованием этого интерфейса `phc2sys` непрерывно синхронизирует PHC на сетевой карте с атомными часами на временной карте. Это обеспечивает точность менее 1 мкс.

Для достижения крайне высокой точности 1PPS выход временной карты должен быть подключен к 1PPS входу сетевой сетевой карты, обеспечивая точность менее 100 нс.

## Обязанности и требования
### COTS-сервер
* Запуск коммерческой ОС
* Интерфейс PCIe
* [необязательно] Поддержка PTM
#### Сетевая сетевая карта (NIC)
* Аппаратные метки времени
* [необязательно] PPS вход/выход
* [необязательно] Поддержка PTM
* [необязательно] Передача времени суток от временной карты к ПО
#### Временная карта (Time Card)
* Задержка (Holdover)
* Вход GNSS
* PPS вход/выход
* Учет секунды в случае вставки (Leap second awareness)
* Время суток
* [необязательно] Поддержка PTM

# Подробная архитектура
Компоненты сборки в реальной жизни могут быть

<a id="Рисунок-3">![Сборка

 открытого временного сервера](/Time-Card/images/OTS_assembly.jpeg)</a>
<p align="center">Рисунок 3. Сборка открытого временного сервера</p>

## COTS-сервер
### Аппаратное обеспечение
Можно использовать большую часть оборудования общего назначения.
Требуется поддержка процессоров vt-d.
Если выбрана многопроцессорная система, рекомендуется подключить временную карту и сетевую сетевую карту к одной и той же линии PCIe. Синхронизация между несколькими процессорами добавит дополнительное смещение.


### Программное обеспечение
Пожалуйста, подробное описание [программного обеспечения](https://github.com/SiwaNetwork/QUANTUM/tree/main/Qantum%20Time-Card/DRV) документа
* Операционная система Linux с драйвером [ocp_ptp](https://github.com/opencomputeproject/Time-Appliance-Project/tree/master/Time-Card/DRV) (включенным в ядро Linux 5.12 и более новое). Драйвер может потребовать включения флага vt-d CPU в BIOS.
* Сервер NTP - [Chrony](https://github.com/mlichvar/chrony)/NTPd, считывающий `/dev/ptpX` с временной карты.
* Сервер PTP - [ptp4u](https://github.com/facebook/time) или [ptp4l](https://github.com/richardcochran/linuxptp), считывающий `/dev/ptpX` с сетевой сетевой карты.
  * [phc2sys](https://github.com/richardcochran/linuxptp)/[ts2phc](https://github.com/richardcochran/linuxptp) для копирования значений часов с временной карты на сетевую сетевую карту
## Сетевая сетевая карта (NIC)
Большую часть оборудования общего назначения можно использовать.
Для улучшения точности NTP или PTP могут потребоваться дополнительные требования ниже.

### Форм-фактор
* Стандартное PCIe Stand-up HHHL Half-Height, Half-Length 
* Одно слот - Пассивное охлаждение
* Поддержка стандартных PCIe для высоких и коротких кронштейнов -или- типов выбрасывателя OCP NIC 3.0

### Интерфейс PCIe
* PCIe Gen3.0/Gen4.0 X n линий на золотых контактах, где n = как минимум 8

### Сетевые порты
* Однопортовый или двухпортовый Ethernet

### Аппаратные метки времени
Сетевая сетевая карта должна выполнять метки времени для всех входящих пакетов.  
Пакеты без PTP меток могут быть объединены и иметь общие метки времени в дескрипторе ПО, пока они не находятся на расстоянии более TBD наносекунд.  
Сетевая сетевая карта должна выполнять метки времени для всех исходящих пакетов PPS.

* PHC
* PTM
* Вход 1PPS
* [необязательно] Вход 10 МГц, который можно использовать в качестве входа частоты для устройства TSU
* [необязательно] Поддержка мультихост

### Вывод PPS
* Подъем/спад PPS Out < 5 нс
* Задержка PPS Out < 400 пс
* Дрожание PPS Out < 250 фемтосекунд
* Сопротивление PPS Out = 50 Ом
* Частота PPS Out 1 Гц - 10 МГц

### Вход PPS
* Задержка входа PPS In < 400 пс
* Дрожание входа PPS In < 250 фемтосекунд
* Сопротивление входа PPS In = 50 Ом
* Частота входа PPS In 1 Гц - 10 МГц


## Временная карта (Qantum Card)

Основная идея заключается в том, что эта карта подключается через интерфейс PCIe к серверу и предоставляет время суток (ToD) через интерфейс `/dev/ptpX`. С использованием этого интерфейса `phc2sys` непрерывно синхронизирует PHC на сетевой карте с атомными часами на временной карте. Это обеспечивает точность менее 1 мкс.

Для достижения крайне высокой точности 1PPS выход временной карты должен быть подключен к 1PPS входу сетевой сетевой карты, обеспечивая точность менее 100 нс. Цена точности на входе PPS временной карты состоит в том, что она берет опорный сигнал от атомных часов (по умолчанию).

[Схема подключения](/Time-Card/images/OTS_Connect.png)

Примечание: Чтобы добиться максимальной точности, важно учесть задержку в соединительных кабелях между временной картой и сетевой сетевой картой. В идеале, кабель не должен иметь задержки, но на практике это невозможно. Необходимо минимизировать длину и задержку кабелей и их влияние на точность синхронизации.


Это спецификация открытого временного сервера версии 1.0. Для более подробной информации и последних обновлений следуйте по [ссылке](https://www.qantum.pro).

