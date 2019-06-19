/*
Firmware de sumorobot basado en sensores ultrasonicos y
sensores de linea infrarrojos, y usa como controlador 
pricipal un microcontrolador ATMega328p aunque el codigo
es portable a otros miconcontroladores compatibles con 
el framework de arduino.
#Autor: 
Wilson Oviedo Hachen || github.com/WilsonOviedo
#Colaboradores:

#
*/
#include <Arduino.h>
#include "movimientos.h"

#define trigSensorFrente      2
#define echoSensorFrente      3
#define trigSensorAtras       4
#define echoSensorAtras       5

#define sensorLineaFrente     A0        //Frente derecha 
#define sensorLineaAtras      A1		//Atras izquierda

#define Blanco 		            1         //Valor digital equivalente
#define Negro                 0         //Valor digital equivalente 

#define Motor1Derecha        10			//Pin PWM Motor 1 derecha
#define Motor1Izquierda      11     	//Pin PWM Motor 1 izquierda
#define Motor2Derecha 	     12			//Pin PWM Motor 2 derecha
#define Motor2Izquierda      13     	//pin PWM Motor 2 izquierda

#define tiempoSeg             5

#define distanciaMax         140		//Centimetro maximo Ring

long duracionFrente, distanciaFrente;  // Variables de Sensor ultrasonico del frente
long duracionAtras, distanciaAtras;  // Variables de Sensor ultrasonico del frente

int SensorLineaFrente;
int SensorLineaAtras;

void setup(){

  pinMode(trigSensorAtras, OUTPUT);
  pinMode(echoSensorAtras, INPUT);
  pinMode(trigSensorFrente, OUTPUT);
  pinMode(echoSensorFrente, INPUT);

  pinMode(sensorLineaAtras, INPUT);
  pinMode(sensorLineaAtras, INPUT);

  pinMode(Motor1Derecha, OUTPUT);
  pinMode(Motor1Izquierda, OUTPUT);
  pinMode(Motor2Derecha, OUTPUT);
  pinMode(Motor2Izquierda, OUTPUT);
}

int lectFrente(){

  /* Hacer el disparo */
  digitalWrite(trigSensorFrente, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigSensorFrente, HIGH);   // Flanco ascendente
  delayMicroseconds(10);                  // Duracion del pulso
  digitalWrite(trigSensorFrente, LOW);    // Flanco descendente

  /* Recepcion del eco de respuesta */
  duracionFrente = pulseIn(echoSensorFrente, HIGH);

  /* Calculo de la distancia efectiva */
  distanciaFrente = (duracionFrente/2) / 29;
  return distanciaFrente;
}
int lectAtras(){

  /* Hacer el disparo */
  digitalWrite(trigSensorAtras, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigSensorAtras, HIGH);    // Flanco ascendente
  delayMicroseconds(10);                  // Duracion del pulso
  digitalWrite(trigSensorAtras, LOW);     // Flanco descendente

  /* Recepcion del eco de respuesta */
  duracionAtras = pulseIn(echoSensorAtras, HIGH);

  /* Calculo de la distancia efectiva */
  distanciaAtras = (duracionAtras/2) / 29;
  return distanciaAtras;
}

int lectLineaFrente(){
  SensorLineaFrente=digitalRead(sensorLineaFrente);
  return SensorLineaFrente;
}

int lectLineaAtras(){
  SensorLineaAtras=digitalRead(sensorLineaAtras);
  return SensorLineaAtras;
}



void loop(){
  millis();
 
  lectAtras();
  lectFrente();

  while(millis()/1000>=tiempoSeg){
    while(lectLineaAtras()==Negro&&lectLineaFrente()==Negro){

      if((distanciaAtras<distanciaMax)&&(distanciaFrente>distanciaMax)){             	//Caso el contrincante se encuentre a la DERECHA
        do{

          MotoresGirarDerecha(200);

        } 
        while (lectFrente()>=distanciaMax||lectAtras()>=distanciaMax);

        stopMotores(); 

      }

      if((distanciaAtras>distanciaMax)&&(distanciaFrente<distanciaMax)){				//Caso el contrincante se encuentre a la IZQUIERDA
        do{

          MotoresGirarIzquierda(200);

        } 
        while (lectFrente()>=distanciaMax||lectAtras()>=distanciaMax);

        stopMotores(); 
      }

    
    }

    lectAtras();
    lectFrente();

  }    
}