// C++ code
//
#define MAX 5
int marcia=1;

int a=7; 
int b=6; 
int c=5; 
int d=11; 
int e=10; 
int f=8; 
int g=9; 
int dp=4; 
bool parkToggle;

void display1(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(c,HIGH);
} 
//display number2
void display2(void) 
{
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);
  	digitalWrite(e,HIGH);
    digitalWrite(d,HIGH);
} 
// display number3
void display3(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
  	digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(g,HIGH);
} 
// display number4
void display4(void) 
{ 
    digitalWrite(f,HIGH);
    digitalWrite(a,HIGH);
    digitalWrite(g,HIGH);
  	digitalWrite(c,HIGH);
  
} 
// display number5
void display5(void) 
{ 
    digitalWrite(b,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
  	digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
} 
// display number6
void display6(void) 
{ 
    digitalWrite(b,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
  	digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);  
    digitalWrite(e,HIGH);  
} 
// display number7
void display7(void) 
{   
   	digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
} 
// display number8
void display8(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);
  	digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);  
    digitalWrite(e,HIGH);  
  	digitalWrite(f,HIGH);  
} 
void clearDisplay(void) 
{ 
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(g,LOW);
  	digitalWrite(c,LOW);
    digitalWrite(d,LOW);  
    digitalWrite(e,LOW);  
  	digitalWrite(f,LOW);  
} 
void display9(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);
  	digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);  
  	digitalWrite(f,HIGH);  
} 
void display0(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
  	digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);  
    digitalWrite(e,HIGH);  
  	digitalWrite(f,HIGH);  
}
void displayN(void){
	digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
  	digitalWrite(c,HIGH);
    //digitalWrite(d,HIGH);  
    digitalWrite(e,HIGH);  
  	digitalWrite(f,HIGH);
}
void displayP(void){
	digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
  	digitalWrite(g,HIGH);  
    digitalWrite(e,HIGH);  
  	digitalWrite(f,HIGH);
}

void setup()
{
  Serial.begin(9600);
  Serial.println("Macchina Avviata");
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  pinMode(12, INPUT);
  int i;
    for(i=4;i<=11;i++) 
        pinMode(i,OUTPUT);
}

void loop()
{
  int piu = digitalRead(2);
  int meno = digitalRead(3);
  int park = digitalRead(12);
  
  if(park==1){
    if(parkToggle==true){
      parkToggle=false;
   	  clearDisplay();
    }
    else
      parkToggle=true;
  }
  if(parkToggle==true){
    marcia = 1;
    Serial.println("PARK");
    displayP();
  }
  if(piu==1){
    if(marcia>=MAX){
    	marcia=MAX;
    }
    else{
  		marcia++;
    	Serial.println("Marcia Aggiunta");
    }
  }
  if(meno==1){
    if(marcia<=0){
    	Serial.println("Retromarcia");
      	marcia=0;
    }
    else{
  		marcia--;
    	Serial.println("Marcia Tolta");
    }
  }
  else
    marcia=marcia;
  
  if(marcia==0){
    clearDisplay();
    Serial.println("Retromarcia");
    displayN();
  }
  if(marcia==1){
    if(parkToggle==1){
      	clearDisplay();
    	displayP();
    }
    else{
  		clearDisplay();
   		display1();
    	Serial.println(marcia);
    }
  }
  if(marcia==2){
  	clearDisplay();
    display2();
    Serial.println(marcia);
  }
  if(marcia==3){
  	clearDisplay();
    display3();
    Serial.println(marcia);
  }
  if(marcia==4){
  	clearDisplay();
    display4();
    Serial.println(marcia);
  }
  if(marcia==5){
  	clearDisplay();
    display5();
    Serial.println(marcia);
  }
  else
    Serial.println(marcia);
  
  delay(150);
}