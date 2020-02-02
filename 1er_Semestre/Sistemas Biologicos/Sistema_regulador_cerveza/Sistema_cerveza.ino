#include "DHT.h"            //Se incluye a la libreria del Sensor DHT22
#include <Servo.h>             //Servo library
float temp;      
DHT dht(4, DHT11);
Servo servo_test;        //initialize a servo object for the connected servo  
                
int angle = 0;    
      
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);       // Inicia comunicación serial
  dht.begin();              // Inicia el sensor
  pinMode(2, OUTPUT);//azul
    pinMode(6, OUTPUT);//rojo
    pinMode(11, OUTPUT);
     servo_test.attach(9);      // attach the signal pin of servo to pin9 of arduino
}

void loop() {
  temp = dht.readTemperature();    //Se guarda la lectura de temperatura en la variable "temperatura"
  Serial.print("Temperatura: ");          //Se imprime la palabra " Temperatura: "
  Serial.print(temp);              //Se imprime el valor obtenido por el sensor    
  Serial.println(" *C ");                 //en grados Celsius
  if(temp>=27){
    digitalWrite(2, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(11, HIGH
    );
  }
  if(temp<=26){
    digitalWrite(6, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(11, LOW);
  }
  delay(10000);                             //Retardo de medio segundo
    for(angle = 0; angle < 180; angle += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test.write(angle);                 //command to rotate the servo to the specified angle
    delay(15);                       
}
 delay(1000);
  
  for(angle = 180; angle>=1; angle-=5)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo_test.write(angle);              //command to rotate the servo to the specified angle
    delay(5);                       
  } 

    delay(1000);
}
