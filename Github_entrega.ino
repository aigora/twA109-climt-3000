#include <OneWire.h>
#include<DallasTemperature.h>

const byte pinDatosDQ=9;
const int ledPIN = 13, Resistencia=12;
byte t,temp=30;

OneWire oneWireObjeto(pinDatosDQ);
DallasTemperature sensorDS18B20(&oneWireObjeto);




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);    //iniciar puerto serie
  pinMode(ledPIN , OUTPUT);  //definir pin como salida
  pinMode(Resistencia , OUTPUT);  //definir Resistencia como salida
  Serial.begin(9600);
  sensorDS18B20.begin();

   
}

void loop() {
  // put your main code here, to run repeatedly:
  
  char temperatura;
  
  if (Serial.available() > 0)
 {
 temperatura = Serial.read();
 }

  if( Serial.available()> 0) {      // Recibimos la temperatura introducida por el usuario.
          int temp = Serial.available();    
        temp = Serial.read();   
        }
  
  Serial.println("Mandando Comandos a los sensores");
  sensorDS18B20.requestTemperatures();
  Serial.print("Temperatura sensor 0: ");
  Serial.println(sensorDS18B20.getTempCByIndex(0));
  
  float t=sensorDS18B20.getTempCByIndex(0);
  Serial.println(t);
  




  if (t<=temp)
  {
  digitalWrite(ledPIN , HIGH);   // poner el Pin en HIGH
  delay(2000);                   // esperar un segundo
    
  } else
  {
    digitalWrite(ledPIN , LOW);    // poner el Pin en LOW
  delay(1000);
  }

  if (t<=temp)
  {
  digitalWrite(Resistencia , HIGH);   // Circula corriente por la resistencia
                    
    
  } else
  {
    digitalWrite(Resistencia , LOW);    // Cortamos corriente en resistencia
  
  }
  
  delay(600);
}
