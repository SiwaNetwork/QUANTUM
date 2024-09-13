# Timetickler

Утилита для запроса и изменения параметров МАК.

## Установка

Respository клонировать и установить требованиям,

`pip install -r requirements.txt`

Используя `pyinstaller` создать исполняемый,

`pyinstaller --onefile timetickler.py`

Это создаст двоичный файл "timetickler" в файле "./dist/", вы можете скопировать этот файл в другой каталог,

`cp ./dist/timetickler /my/directory/here`

Это создаст двоичный файл "timetickler" в файле "./dist/", вы можете скопировать этот файл в другой каталог,

```
./timetickler list
```

Чтобы запросить поле,

```
./timetickler get Phase
```
Одновременно можно запросить несколько полей,

```
./timetickler get Phase LastCorrection PpsOffset
```

По умолчанию `timetickler` выводит результат одного запроса, для указания количества запросов используйте флаг `-n`,
```
# output 10 readings
./timetickler get Phase -n 10
```

Чтобы запросить поле или поля до тех пор, пока пользователь не завершит его, укажите "-1`,

```
./timetickler get Phase -n -1
```

Чтобы задать поле,

```
./timetickler set PpsOffset 1234
```

Чтобы задать поле и сохранить его значение после сброса табеля учета рабочего времени, сохраните это значение,

```
./timetickler set PpsOffset 1234 --store
```

