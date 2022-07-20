/*
Color Sensor      Arduino
-----------      --------
VCC               5V
GND               GND
s0                8
s1                9
s2                10
s3                11
OUT               12
OE                GND
*/

//Variaveis dos pinos do sensor1
const int s0 = 53;
const int s1 = 52;
const int s2 = 51;
const int s3 = 50;
const int out = 49;

//Variaveis dos pinos do sensor2 (Não vai ser inserido no codigo ainda) 

const int s0_2 = 0;
const int s1_2 = 1;
const int s2_2 = 2;
const int s3_2 = 3;
const int out_2 = 4;

// Variaveis
int red = 0;
int green = 0;
int blue = 0;

void color(){
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);


  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);

   
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);


  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  
}
void color_2() { //Para o sensor 2;
  
  digitalWrite(s2_2, LOW);
  digitalWrite(s3_2, LOW);
  
  red = pulseIn(out_2, digitalRead(out_2) == HIGH ? LOW : HIGH);
  digitalWrite(s3_2, HIGH);
  
  blue = pulseIn(out_2, digitalRead(out_2) == HIGH ? LOW : HIGH);
  digitalWrite(s2_2, HIGH);


  green = pulseIn(out_2, digitalRead(out_2) == HIGH ? LOW : HIGH);
  
  
}
  
void sensorcor_1() {
  color();
  Serial.print("R Intensity:");
  Serial.print(red, DEC);
  Serial.print(" G Intensity: ");
  Serial.print(green, DEC);
  Serial.print(" B Intensity : ");
  Serial.print(blue, DEC);

  //Serial.println();
  if (red < blue && red < green && red < 20){
    Serial.println(" - (Red Color)");
    
  }else if (blue < red && blue < green){
    Serial.println(" - (Blue Color)");
    
  }else if (green < red && green < blue){
    Serial.println(" - (Green Color)");
    
  }else{
    Serial.println();
  }

  delay(50);
}

void sensorcor_2(){
  color_2();
  Serial.print("sensor 2");
  Serial.print("R Intensity:");
  Serial.print(red, DEC);
  Serial.print(" G Intensity: ");
  Serial.print(green, DEC);
  Serial.print(" B Intensity : ");
  Serial.print(blue, DEC);

  //Serial.println();
  if (red < blue && red < green && red < 20){
    Serial.println(" - (Red Color) 2");
    
  }else if (blue < red && blue < green){
    Serial.println(" - (Blue Color) 2 ");
    
  }else if (green < red && green < blue){
    Serial.println(" - (Green Color) 2");
    
  }else{
    Serial.println();
  }

}


void setup(){
  Serial.begin(9600);
//Sensor 1
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
//Sensor 2
  pinMode(s0_2, OUTPUT);
  pinMode(s1_2, OUTPUT);
  pinMode(s2_2, OUTPUT);
  pinMode(s3_2, OUTPUT);
  pinMode(out_2, INPUT);
  digitalWrite(s0_2, HIGH);
  digitalWrite(s1_2, HIGH);


  
  
}

void loop(){
  sensorcor_1();
  delay(1000);
  sensorcor_2();
  delay(1000);
  
  
}
