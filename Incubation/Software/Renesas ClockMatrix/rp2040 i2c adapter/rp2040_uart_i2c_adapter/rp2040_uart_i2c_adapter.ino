/*
 ###  Самые простые часы на Arduino UNO ###

 Для проекта часов нужны только жк-дисплей 16х2 LCD и 2 кнопки
 Никаких потенциометров для контраса, никаких резисторов 
 Функции кнопок:
 
 - короткое нажатие одной из кнопок включает подсветку на 30 с
 
 Настройка времени
 - Нажмите H для увеличения Часов
 - Нажмите M для увеличения Минут и сброса секунд
*/

#include "LiquidCrystal.h"

// Определяем соединение ЖК-дисплея с цифровыми контактами
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Настройка контрастности ЖК
int cs=9;// пин 9 для контраста ШИМ
const int contrast = 100;// контраст по умолчанию

// Начальное отображение времени 12:59:45 PM
int h=12;
int m=59;
int s=45;
int flag=1; //PM

// Кнопки установки времени
int button1;
int button2;

// Определение пинов для Кнопок установки времени
int hs=0;// pin 0 для настройки Часов
int ms=1;// pin 1 для настройки Минут

// Тайм-аут подсветки 
const int Time_light=150;
int bl_TO=Time_light;// Тайм-аут подсветки
int bl=10; // Пин подсветки
const int backlight=120; // НЕ БОЛЕЕ 7mA !!!

// Для точного считывания времени используйте часы реального времени Arduino, а не только задержку delay()
static uint32_t last_time, now = 0; // RTC

void setup()
{
  lcd.begin(16,2);
  pinMode(hs,INPUT_PULLUP);// избегать внешних Pullup резисторов для кнопки 1
  pinMode(ms,INPUT_PULLUP);// и кнопки 2
  analogWrite(cs,contrast);// Настроить контрастность VO
  analogWrite(bl,backlight);// Включить подсветку 
  now=millis(); // читать начальное значение RTC  
}

void loop()
{ 
  lcd.begin(16,2);// каждую секунду
// Обновить ЖК-дисплей
// Вывести время TIME в Hour, Min, Sec + AM/PM (часы, минуты, секунды)
 lcd.setCursor(0,0);
 lcd.print("Time ");
 if(h<10)lcd.print("0");// всегда 2 цифры
 lcd.print(h);
 lcd.print(":");
 if(m<10)lcd.print("0");
 lcd.print(m);
 lcd.print(":");
 if(s<10)lcd.print("0");
 lcd.print(s);

 if(flag==0) lcd.print(" AM");
 if(flag==1) lcd.print(" PM");
 
 lcd.setCursor(0,1);// для Line 2
 lcd.print("Precision clock");

// улучшенная замена delay(1000) 
// гораздо лучшая точность, менее зависимая от времени выполнения цикла

for ( int i=0 ;i<5 ;i++)// сделать 5-кратный цикл 200 мс, для более быстрого ответа кнопок
{
  while ((now-last_time)<200) //задержка delay 200ms
  { 
    now=millis();
  }
 // внутренний цикл 200ms
 last_time=now; // готовим следующий цикл 

 // read Setting Buttons (читаем кнопки настройки)
 button1=digitalRead(hs);// Read Buttons
 button2=digitalRead(ms);

 //Время подсветки 
 bl_TO--;
 if(bl_TO==0)
 {
  analogWrite(bl,0);// ВЫКЛ подсветки
  bl_TO++;
 }
 
 // Нажмите что-либо, чтобы активировать подсветку 
 if(  ((button1==0)|(button2==0)) & (bl_TO==1)  )
 {
  bl_TO=Time_light;
  analogWrite(bl,backlight);
  // дождитесь отпускания кнопки
  while ((button1==0)|(button2==0))
  {
   button1=digitalRead(hs);// Read Buttons
   button2=digitalRead(ms);
  }
 }
 else
 // Поведение Кнопки 1 или Кнопки 2 пока подсветка ВКЛ 
 {
  if(button1==0){
   h=h+1;
   bl_TO=Time_light;
   analogWrite(bl,backlight);
  }

 if(button2==0){
  s=0;
  m=m+1;
  bl_TO=Time_light;
  analogWrite(bl,backlight);
  }

/* ---- управлять секундами, минутами, часами am / pm ----*/
 if(s==60){
  s=0;
  m=m+1;
 }
 if(m==60)
 {
  m=0;
  h=h+1;
 }
 if(h==13)
 {
  h=1;
  flag=flag+1;
  if(flag==2)flag=0;
 }

 if((button1==0)|(button2==0))// Обновить дисплей, если нажата кнопка
 {
  // Обновить ЖК
  // Вывести время TIME в часах, минутах, секундах + AM/PM
  lcd.setCursor(0,0);
  lcd.print("Time ");
  if(h<10)lcd.print("0");// всегда 2 цифры
  lcd.print(h);
  lcd.print(":");
  if(m<10)lcd.print("0");
  lcd.print(m);
  lcd.print(":");
  if(s<10)lcd.print("0");
  lcd.print(s);

  if(flag==0) lcd.print(" AM");
  if(flag==1) lcd.print(" PM");
 
  lcd.setCursor(0,1);// для Line 2
  lcd.print("Precision clock");
 }

 } // end if else
}// end for

// outer 1000ms loop (завершение цикла)
 s=s+1; //увеличение секунд
        
// ---- управлять секундами, минутами, часами + am/pm ----
 if(s==60){
  s=0;
  m=m+1;
 }
 if(m==60)
 {
  m=0;
  h=h+1;
 }
 if(h==13)
 {
  h=1;
  flag=flag+1;
  if(flag==2)flag=0;
 }  
// Loop end (конец цикла)
}
