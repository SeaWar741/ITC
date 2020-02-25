#include "DHT.h"  

DHT dht(5, DHT11);

float temp;
int led=4;//Focos

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);       // Inicia comunicación serial
  dht.begin();              // Inicia el sensor
  pinMode(led,OUTPUT);
}

void loop() {
  temp = dht.readTemperature();    //Se guarda la lectura de temperatura en la variable "temperatura"
  Serial.print("Temperatura: ");          //Se imprime la palabra " Temperatura: "
  Serial.print(temp);              //Se imprime el valor obtenido por el sensor    
  Serial.println(" *C ");                 //en grados Celsius
  
  digitalWrite(led,HIGH);
  delay(1000);
  digitalWrite(led,LOW);
  delay(1000);
}
