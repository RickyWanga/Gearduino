//@Author RickyWanga
#define MAX 5
//set the default gear on 1
int marcia=1;
//initialize the 7-segment display pins
int a=7; 
int b=6; 
int c=5; 
int d=11; 
int e=10; 
int f=8; 
int g=9; 
int dp=4; 
//define the bool variable for the Park position on the gearbox
bool parkToggle;

//Display 1 on the 7-segment LED display
void display1(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(c,HIGH);
} 
//Display 2 on the 7-segment LED display
void display2(void) 
{
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(d,HIGH);
} 
//Display 3 on the 7-segment LED display
void display3(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(g,HIGH);
} 
//Display 4 on the 7-segment LED display
void display4(void) 
{ 
    digitalWrite(f,HIGH);
    digitalWrite(a,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(c,HIGH);
  
} 
//Display 5 on the 7-segment LED display
void display5(void) 
{ 
    digitalWrite(b,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
} 
//Display 6 on the 7-segment LED display
void display6(void) 
{ 
    digitalWrite(b,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);  
    digitalWrite(e,HIGH);  
} 
//Display 7 on the 7-segment LED display
void display7(void) 
{   
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
} 
//Display 8 on the 7-segment LED display
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
//Displays 9 on the 7-segment LED display
void display9(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);  
    digitalWrite(f,HIGH);  
} 
//Displays 0 on the 7-segment LED display
void display0(void) 
{ 
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);  
    digitalWrite(e,HIGH);  
    digitalWrite(f,HIGH);  
}
//Displays a N on the 7-segment LED display
void displayN(void){
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH); 
    digitalWrite(e,HIGH);  
    digitalWrite(f,HIGH);
}
//Displays a P on the 7-segment LED display
void displayP(void){
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(g,HIGH);  
    digitalWrite(e,HIGH);  
    digitalWrite(f,HIGH);
}
//Clears the 7-segment LED display
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

void setup()
{
  //intialize the serial monitor for debugging purposes
  Serial.begin(9600);
  Serial.println("Macchina Avviata");
  //set the input types for the button related to the UpShift, DownShift and the Park position
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  pinMode(12, INPUT);
  //set the pinMode for the 7-segment LED display
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
