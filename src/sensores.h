#include <Arduino.h>
#include "config.h"

long duracion, distancia;       // Variables de Sensor ultrasonico

int LecSensorLinea;

long lect_Ultrasonic(byte trigSensor, byte echoSensor)
{

  /* Hacer el disparo */
  digitalWrite(trigSensor, LOW);
  delayMicroseconds(2);
  digitalWrite(trigSensor, HIGH); // Flanco ascendente
  delayMicroseconds(10);          // Duracion del pulso
  digitalWrite(trigSensor, LOW);  // Flanco descendente

  /* Recepcion del eco de respuesta */
  duracion = pulseIn(echoSensor, HIGH);

  /* Calculo de la distancia efectiva */
  distancia = (duracion / 2) / 29;
  return distancia;
}

int lect_Linea(byte SensorLinea)
{
  LecSensorLinea = digitalRead(SensorLinea);
  return LecSensorLinea;
}