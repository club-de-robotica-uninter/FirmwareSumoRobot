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

//Variables globales
int tiempo=0,tiempo1 = 0;

void setup()
{
  tiempo1 = millis();

  
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
tiempo=tiempoSeg*1000;
while ((millis() - tiempo1) < tiempo)
  ;

desplegarRampa();
}

void loop()
{
    
  while (lect_Ultrasonico(trigSensorAtras, echoSensorAtras) < distanciaMax && lect_Linea(sensorLineaAtras) == Negro && lect_Linea(sensorLineaFrente) == Negro)
  {
    
    MoverAtras(255);
  }

  while (lect_Ultrasonico(trigSensorFrente, echoSensorFrente) < distanciaMax && lect_Linea(sensorLineaAtras) == Negro && lect_Linea(sensorLineaFrente) == Negro)
  {
    
    MoverFrente(255);
  }


if (lect_Linea(sensorLineaFrente)==Blanco&&lect_Linea(sensorLineaAtras)==Negro )
{
  MoverAtras(255);
  delay(500);
  stopMotores();
}

if (lect_Linea(sensorLineaFrente)==Negro&&lect_Linea(sensorLineaAtras)==Blanco )
{
  MoverFrente(255);
  delay(500);
  stopMotores();
}

while (lect_Ultrasonico(trigSensorAtras,echoSensorAtras)>distanciaMax&&lect_Ultrasonico(trigSensorFrente,echoSensorFrente)>distanciaMax)
{
   GirarDerecha(255 );
  
}

}