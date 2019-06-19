#include <Arduino.h>
#include "config.h"

void MotoresFrente(int vel){
  analogWrite(Motor1Derecha, vel);
  analogWrite(Motor1Izquierda, 0);

  analogWrite(Motor2Derecha, vel);
  analogWrite(Motor2Izquierda, 0);
}

void MotoresAtras(int vel){
  analogWrite(Motor1Derecha, 0);
  analogWrite(Motor1Izquierda, vel);

  analogWrite(Motor2Derecha, 0);
  analogWrite(Motor2Izquierda, vel);
}

void MotoresGirarDerecha(int vel){
  analogWrite(Motor1Derecha, 0);
  analogWrite(Motor1Izquierda, vel);

  analogWrite(Motor2Derecha, vel);
  analogWrite(Motor2Izquierda, 0);
}

void MotoresGirarIzquierda(int vel){
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
