/*
Firmware de sumorobot basado en sensores ultrasonicos y
sensores de linea infrarrojos, y usa como controlador 
pricipal un microcontrolador ATMega328p aunque el codigo
es portable a otros miconcontroladores compatibles con 
el framework de arduino.

#Colaboradores:
Wilson Oviedo Hachen || github.com/WilsonOviedo

*/

#include <Arduino.h>
#include "movimientos.h"
#include "sensores.h"


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





void loop(){
  millis();
 
  lectAtras();
  lectFrente();

  while(millis()/1000>=tiempoSeg){
    while(lectLineaAtras()==Negro&&lectLineaFrente()==Negro){

      if((distanciaAtras<distanciaMax)&&(distanciaFrente>distanciaMax)){       	//Caso el contrincante se encuentre a la DERECHA
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