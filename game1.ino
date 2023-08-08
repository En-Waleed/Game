#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int score=0,state1,state2 , lastscore=0;

void setup()
{lcd.init();
 lcd.backlight();
 for(int i=0;i<=13;i++)
   pinMode(i,OUTPUT);
   pinMode(A0,OUTPUT);
   pinMode(A1,OUTPUT);
   pinMode(A2,INPUT_PULLUP);
   pinMode(A3,INPUT_PULLUP);
  lcd.setCursor(0,0);
  lcd.print("loading game....");
 delay(250);
 lcd.clear();
}

void loop()
{
  lcd.setCursor(8,0);
  lcd.print("score:");
  lcd.setCursor(0,0);
  lcd.print("        ");
  lcd.setCursor(0,1);
  lcd.print(">");
    lastscore = score;
  
  for(int x=16;x>=0;x--)
    {lcd.setCursor(x,1);
    lcd.print("#");
    lcd.setCursor(x+1,1);
    lcd.print(" ");
    delay(50);
    tone(A0,135);
    noTone(A1);

    if(digitalRead(A2)==LOW)
      {lcd.setCursor(0,0);
      lcd.print(">");
      lcd.setCursor(0,1);
      lcd.print(" ");
      score++;
      noTone(A0);
      tone(A1,100);
      delay(10);
      while(digitalRead(A2)==LOW){}}
    if(x==1 && score == lastscore){
      for(int w=100;w<10000;w=w+200)
      {noTone(A0);
       tone(A1,w);
       x=16;delay(50);}
       lcd.setCursor(1,1);
       lcd.print(" ");
       score=0;}
   
  state1=score%10;
  switch (state1){
case 1:
  digitalWrite(0, LOW);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);   //1
  digitalWrite(4, LOW); 
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);break;
case 2:
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);  //2
  digitalWrite(4, HIGH); 
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);break;
case 3:
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);  //3 
  digitalWrite(4, LOW); 
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);break;
case 4:
  digitalWrite(0, LOW);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);   //4
  digitalWrite(4, LOW); 
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);break;
case 5:
  digitalWrite(0, HIGH);
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);  //5
  digitalWrite(4, LOW); 
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);break;
case 6:
  digitalWrite(0, HIGH);
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);  //6
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH); 
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);break;
case 7:
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);  //7
  digitalWrite(4, LOW); 
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);break;
case 8:
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);  //8
  digitalWrite(4, HIGH); 
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);break;
case 9:
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);  //9
  digitalWrite(4, LOW); 
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);break;
default:   
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);  //0
  digitalWrite(4, HIGH); 
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW); break;}
    
  state2=score/10;
  switch (state2){
case 1:
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);   //1
  digitalWrite(11, LOW); 
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);break;
case 2:
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);  //2
  digitalWrite(11, HIGH); 
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);break;
case 3:
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);  //3 
  digitalWrite(11, LOW); 
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);break;
case 4:
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);   //4
  digitalWrite(11, LOW); 
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);break;
case 5:
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);  //5
  digitalWrite(11, LOW); 
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);break;
case 6:
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);  //6
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH); 
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);break;
case 7:
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);  //7
  digitalWrite(11, LOW); 
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);break;
case 8:
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);  //8
  digitalWrite(11, HIGH); 
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);break;
case 9:
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);  //9
  digitalWrite(11, LOW); 
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);break;
default:   
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);  //0
  digitalWrite(11, HIGH); 
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW); break;}
   
    lcd.setCursor(14,0);
    lcd.print(score);
   
   if(digitalRead(A3)==LOW){
    lcd.clear();
    lcd.print("RESTRTING GAME ");
    noTone(A0);
    tone(A1,200);  
     score=0;
     delay(100);
     x=16;
     lcd.setCursor(8,0);
     lcd.print("score:");
     lcd.setCursor(0,0);
     lcd.print("        ");
     lcd.setCursor(0,1);
     lcd.print(">");
   }
  }
}
