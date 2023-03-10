
#include <Servo.h>
int echo=6;
int trig=7;
int servo_pin=8;
int timer;
int distance;
Servo motor;

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  
  Serial.begin(9600);
  motor.attach(servo_pin);
}

void loop() {
  
  digitalWrite(trig,HIGH); // mesafe aralıgını iyi bir sekilde almamız icin 
                           //belirli aralıklarla sinyali kesmemiz lazım
  delayMicroseconds(1000);
  digitalWrite(trig,LOW);

  timer = pulseIn(echo,HIGH); // pulseIn komutu bizim emir verdigimiz pinini(echo) takibe alır. 
                              //echo pini hıgh oldugu zaman bir kronometre baslatır.
                              //echo pini low olana kadar bu kronometre devam eder. 
                              //low oldugunda kronometrede okunan degeri sure degiskenine aktarır.

  distance = (timer/2) / 29.1;  // ses dalgası gidis ve gelis olarak dusunursek sadece tek yönlü tarafı seçmeliyiz.
                               //bu yüzden 2 ye bölüyoruz. 
                               //Sıcaklıga bağlı olarak ses hızı degistiginden 29. e bölüyoruz

  Serial.println(distance);
  if(distance<8){
    motor.write(180);
    delay(4000);
    motor.write(0);
    
  }
}
