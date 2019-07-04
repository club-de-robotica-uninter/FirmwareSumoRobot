#include <Arduino.h>

/*Archivo de configuracion del sumorobot*/

//Pines del sensor ultrasonico
#define trigSensorFrente      A2
#define echoSensorFrente      A3 
#define trigSensorAtras       A4
#define echoSensorAtras       A5

//Pines del sensor de linea
#define sensorLineaFrente     A1        //Frente derecha 
#define sensorLineaAtras      A0		//Atras izquierda
//Definimos patrones de colores de linea
#define Blanco 		          0         //Valor digital equivalente
#define Negro                 1         //Valor digital equivalente 
//Pines de conexion de puente H para los motores
#define Motor1Derecha        5			//Pin PWM Motor 1 derecha
#define Motor1Izquierda      6     	    //Pin PWM Motor 1 izquierda
#define Motor2Derecha 	     9			//Pin PWM Motor 2 derecha
#define Motor2Izquierda      10     	//pin PWM Motor 2 izquierda

//Tiempo de inicio del robot
#define tiempoSeg             3.5
//Distancia maxima para detectar oponente
#define distanciaMax         100		//Centimetro maximo Ring


