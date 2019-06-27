#include <Arduino.h>
#include "config.h"

void MoverFrente(int vel){
  analogWrite(Motor1Derecha, vel);
  analogWrite(Motor1Izquierda, 0);

  analogWrite(Motor2Derecha, vel);
  analogWrite(Motor2Izquierda, 0);
}

void MoverAtras(int vel){
  analogWrite(Motor1Derecha, 0);
  analogWrite(Motor1Izquierda, vel);

  analogWrite(Motor2Derecha, 0);
  analogWrite(Motor2Izquierda, vel);
}

void GirarDerecha(int vel){
  analogWrite(Motor1Derecha, 0);
  analogWrite(Motor1Izquierda, vel);

  analogWrite(Motor2Derecha, vel);
  analogWrite(Motor2Izquierda, 0);
}

void GirarIzquierda(int vel){
  analogWrite(Motor1Derecha, vel);
  analogWrite(Motor1Izquierda, 0);

  analogWrite(Motor2Derecha, 0);
  analogWrite(Motor2Izquierda, vel);
}

void stopMotores(){
  analogWrite(Motor1Derecha, 0);
  analogWrite(Motor1Izquierda, 0);

  analogWrite(Motor2Derecha, 0);
  analogWrite(Motor2Izquierda, 0);
}
