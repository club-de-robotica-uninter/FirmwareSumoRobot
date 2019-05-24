#include <Arduino.h>

#define trigSensorFrente      2
#define echoSensorFrente      3
#define trigSensorAtras       4
#define echoSensorAtras       5
#define trigSensorIzq         6
#define echoSensorIzq         7
#define trigSensorDer         8
#define echoSensorDer         9

#define sensorLineaFrenteDer  A0        //Frente derecha 
#define sensorLineaFrenteIzq  A1		//Frente izquiuerda
#define sensorLineaAtrasDer   A2		//Atras derecha
#define sensorLineaAtrasIzq   A3		//Atras izquierda

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
long duracionIzq, distanciaIzq;  // Variables de Sensor ultrasonico del frente
long duracionDer, distanciaDer;  // Variables de Sensor ultrasonico del frente

int SensorLineaFrenteIzq,SensorLineaFrenteDer;
int SensorLineaAtrasIzq,SensorLineaAtrasDer;

void setup(){

  pinMode(trigSensorDer, OUTPUT);
  pinMode(echoSensorDer, INPUT);
  pinMode(trigSensorIzq, OUTPUT);
  pinMode(echoSensorIzq, INPUT);
  pinMode(trigSensorAtras, OUTPUT);
  pinMode(echoSensorAtras, INPUT);
  pinMode(trigSensorFrente, OUTPUT);
  pinMode(echoSensorFrente, INPUT);

  pinMode(sensorLineaAtrasIzq, INPUT);
  pinMode(sensorLineaAtrasDer, INPUT);
  pinMode(sensorLineaFrenteIzq, INPUT);
  pinMode(sensorLineaFrenteDer, INPUT);

  pinMode(Motor1Derecha, OUTPUT);
  pinMode(Motor1Izquierda, OUTPUT);
  pinMode(Motor2Derecha, OUTPUT);
  pinMode(Motor2Izquierda, OUTPUT);
}

int lectFrente(){

  /* Hacer el disparo */
  digitalWrite(trigSensorFrente, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigSensorFrente, HIGH);  // Flanco ascendente
  delayMicroseconds(10);        // Duracion del pulso
  digitalWrite(trigSensorFrente, LOW);  // Flanco descendente

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
  digitalWrite(trigSensorAtras, HIGH);  // Flanco ascendente
  delayMicroseconds(10);        // Duracion del pulso
  digitalWrite(trigSensorAtras, LOW);  // Flanco descendente

  /* Recepcion del eco de respuesta */
  duracionAtras = pulseIn(echoSensorAtras, HIGH);

  /* Calculo de la distancia efectiva */
  distanciaAtras = (duracionAtras/2) / 29;
  return distanciaAtras;
}
int lectIzq(){

  /* Hacer el disparo */
  digitalWrite(trigSensorIzq, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigSensorIzq, HIGH);  // Flanco ascendente
  delayMicroseconds(10);        // Duracion del pulso
  digitalWrite(trigSensorIzq, LOW);  // Flanco descendente

  /* Recepcion del eco de respuesta */
  duracionIzq = pulseIn(echoSensorIzq, HIGH);

  /* Calculo de la distancia efectiva */
  distanciaIzq = (duracionIzq/2) / 29;
  return distanciaIzq;
}
int lectDer(){

  /* Hacer el disparo */
  digitalWrite(trigSensorDer, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigSensorDer, HIGH);  // Flanco ascendente
  delayMicroseconds(10);        // Duracion del pulso
  digitalWrite(trigSensorDer, LOW);  // Flanco descendente

  /* Recepcion del eco de respuesta */
   duracionDer = pulseIn(echoSensorDer, HIGH);
   
  /* Calculo de la distancia efectiva */
  distanciaDer = (duracionDer/2) / 29;
  return distanciaDer;
}
int lectLineaFrenteDerecha(){
  SensorLineaFrenteDer=digitalRead(A0);
  return SensorLineaFrenteDer;
}
int lectLineaFrenteIzquierda(){
  SensorLineaFrenteIzq=digitalRead(A1);
  return SensorLineaFrenteIzq;
}
int lectLineaAtrasDerecha(){
  SensorLineaAtrasDer=digitalRead(A2);
  return SensorLineaAtrasDer;
}
int lectLineaAtrasIzquierda(){
  SensorLineaAtrasIzq=digitalRead(A3);
  return SensorLineaAtrasIzq;
}
void movMotores(int M1Der, int M1Izq, int M2Der, int M2Izq){
  analogWrite(Motor1Derecha, M1Der);
  analogWrite(Motor1Izquierda, M1Izq);

  analogWrite(Motor2Derecha, M2Der);
  analogWrite(Motor2Izquierda, M2Izq);
}

void stopMotores(){
  analogWrite(Motor1Derecha, 0);
  analogWrite(Motor1Izquierda, 0);

  analogWrite(Motor2Derecha, 0);
  analogWrite(Motor2Izquierda, 0);
}


void loop(){
  millis();
  lectDer();
  lectIzq();
  lectAtras();
  lectFrente();

  while(millis()/1000>=tiempoSeg){
    while(lectLineaAtrasIzquierda()==Negro&&lectLineaAtrasDerecha()==Negro&&lectLineaFrenteDerecha()==Negro&&lectLineaFrenteIzquierda()==Negro){

      if((distanciaDer<=distanciaMax)&&(distanciaIzq>distanciaMax)&&(distanciaAtras>distanciaMax)&&(distanciaFrente>distanciaMax)){             	//Caso el contrincante se encuentre a la DERECHA
        do{

          movMotores(1,0,0,1);

        } 
        while (lectFrente()>=distanciaMax||lectAtras()>=distanciaMax);

        stopMotores(); 

      }

      if((distanciaDer>distanciaMax)&&(distanciaIzq<=distanciaMax)&&(distanciaAtras>distanciaMax)&&(distanciaFrente>distanciaMax)){				//Caso el contrincante se encuentre a la IZQUIERDA
        do{

          movMotores(0,1,1,0);

        } 
        while (lectFrente()>=distanciaMax||lectAtras()>=distanciaMax);

        stopMotores(); 
      }

      if((distanciaDer>distanciaMax)&&(distanciaIzq>distanciaMax)&&(distanciaAtras<=distanciaMax)&&(distanciaFrente>distanciaMax)){				//Caso el contrincante se encuentre ATRAS

        movMotores(1,0,1,0);

      }
      if((distanciaDer>distanciaMax)&&(distanciaIzq>distanciaMax)&&(distanciaAtras>distanciaMax)&&(distanciaFrente<=distanciaMax)){				//Caso el contrincante se encuentre ENFRENTE

        movMotores(0,1,0,1);

      }
    }

    lectDer();
    lectIzq();
    lectAtras();
    lectFrente();

  }    
}