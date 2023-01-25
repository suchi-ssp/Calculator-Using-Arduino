#include<LiquidCrystal.h> 
#include<Keypad.h>       
const byte ROWS=4;      
const byte COLS=4;      
char keys[ROWS][COLS]={   
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'C','0','=','+'} 
};
byte rowPins[ROWS]={7,6,5,4};  
byte colPins[COLS]={3,2,1,0};  
Keypad kpd = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);  
const int rs=9, en=8, d4=13 ,d5=12 ,d6=11 ,d7=10;      
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int Num1,Num2,Number;
char key,action;
boolean result= false;
 
void setup() {
  lcd.begin(16,2);   
  lcd.print("arduino"); 
  lcd.setCursor(0,1);    
  lcd.print("calculator");  
  delay(1000);  
  lcd.clear();  
}
void loop() {
  key = kpd.getKey();//storing pressed key value
  if(key!=NO_KEY)
  DetectButtons();
  if(result==true)
  CalculateResult();
  DisplayResult();
}
void DetectButtons()
{
  lcd.clear();
  if(key=='C') //if cancle button is pressed
  {
    Serial.println("Button Cancle");
    Number=Num1=Num2=0;
    result=false;
  }

 
 if(key=='1')
  {
    Serial.println("Button 1");
    if(Number==0)
    Number=1;
    else
    Number=(Number*10)+1; //pressed twice
  }
   if(key=='4')
  {
    Serial.println("Button 4");
    if(Number==0)
    Number=4;
    else
    Number=(Number*10)+4; //pressed twice
  }
   if(key=='7')
  {
    Serial.println("Button 7");
    if(Number==0)
    Number=7;
    else
    Number=(Number*10)+7; //pressed twice
  }
   if(key=='0')
  {
    Serial.println("Button 0");
    if(Number==0)
    Number=0;
    else
    Number=(Number*10)+0; //pressed twice
  }
   if(key=='2')
  {
    Serial.println("Button 2");
    if(Number==0)
    Number=2;
    else
    Number=(Number*10)+2; //pressed twice
  }
   if(key=='5')
  {
    Serial.println("Button 5");
    if(Number==0)
    Number=5;
    else
    Number=(Number*10)+5; //pressed twice
  }
   if(key=='8')
  {
    Serial.println("Button 8");
    if(Number==0)
    Number=8;
    else
    Number=(Number*10)+8; //pressed twice
  }
   if(key=='=')
  {
    Serial.println("Button equal");
    Num2=Number;
    result=true;
  }
   if(key=='3')
  {
    Serial.println("Button 3");
    if(Number==0)
    Number=1;
    else
    Number=(Number*10)+3; //pressed twice
  }
   if(key=='6')
  {
    Serial.println("Button 6");
    if(Number==0)
    Number=6;
    else
    Number=(Number*10)+6; //pressed twice
  }
   if(key=='9')
  {
    Serial.println("Button 9");
    if(Number==0)
    Number=9;
    else
    Number=(Number*10)+9; //pressed twice
  }
  
  if (key=='+'||key=='-'||key=='*'||key=='/')
  {
    Num1=Number;
    Number=0;
    if(key=='+')
    {
      Serial.println("Addition");
      action='+';
    }
    if(key=='-')
    {
      Serial.println("Subtraction");
      action='-';
    }
     if(key=='*')
    {
      Serial.println("Multiplication");
      action='*';
    }
     if(key=='/')
    {
      Serial.println("division");
      action='/';
    }
    delay(100);
  }
}
void CalculateResult()
{
  if(action=='+')
    Number=Num1+Num2;
     if(action=='-')
    Number=Num1-Num2;
     if(action=='*')
    Number=Num1*Num2;
     if(action=='/')
    Number=Num1/Num2;
}
void DisplayResult()
{
  lcd.setCursor(0,0); 
  lcd.print(Num1);
  lcd.print(action);
  lcd.print(Num2);

  if(result==true)
  {
    lcd.print("=");
    lcd.print(Number); 
  }
  lcd.setCursor(0,1); 
  lcd.print(Number);  
}
