#include <Arduino.h>
#include "config.h"

long duracionFrente, distanciaFrente;  // Variables de Sensor ultrasonico del frente
long duracionAtras, distanciaAtras;  // Variables de Sensor ultrasonico del frente

int SensorLineaFrente;
int SensorLineaAtras;

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