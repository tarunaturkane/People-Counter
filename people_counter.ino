#include <LiquidCrystal.h>

LiquidCrystal led(8,9,10,11,12,13);
int door1=7;
int door2=5;
int people=0;
bool i;
int buzzer=4;
int tm=3;  /*tm represent the analog pin no. where temp sensor is connected*/
int j;


void setup()
{ pinMode(door1,INPUT);
  pinMode(door2,INPUT);  
  pinMode(tm,INPUT);
  led.begin(16,2); 
  
}

void loop()
{ while(digitalRead(door1)==LOW && digitalRead(door2)==LOW)
{}
  i=digitalRead(door1);
  if(i==HIGH)
  {   led.clear();
      led.print("People entering");
      if((j=analogRead(tm))>=180)
        { tone(buzzer,1000,100);
          led.setCursor(3,1);
          led.print("Suspected");
          led.blink();
        } 
    
    while(digitalRead(door2)==LOW){}
    led.clear();
    led.noBlink();
    if((j=analogRead(tm))>=180)
    {
      tone(buzzer,1000,100);
    }
    led.print("People entered");
    led.setCursor(3,1);
    led.print("WELCOME");
    people++;
    while(digitalRead(door2)==HIGH){}
    led.clear();
  }
  else
  { led.clear();
    led.print("People leaving");
    if((j=analogRead(tm))>=180)
    {
      tone(buzzer,1000,100);
    }
    while(digitalRead(door1)==LOW){}
    led.clear();
    if((j=analogRead(tm))>=180)
    {
      tone(buzzer,1000,100);
    }
    led.print("  People left  ");
    led.setCursor(3,1);
    led.print("GOOD BYE");
    people--;
    while(digitalRead(door1)==HIGH){}
    led.clear();  
  }
 
 led.print("No of people: ");
 led.print(people);
}
