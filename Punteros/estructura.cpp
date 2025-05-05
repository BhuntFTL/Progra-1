/*
 	Clase del 2 de abril del 2025
 	
 	Trabajando estructras con punteros (llenandolos, mostrandolos...)
 
 */
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string.h>
using namespace std;

//Datos
struct Datos{
   int num;
   float calif;
   char nombre[35];
};

//Prototipo de funciones
void mostrar(Datos);

//Programa principal
int main(){
   srand(time(NULL));

    Datos persona, *ptrPer;
   ptrPer = &persona;

   //almacenar valores en la estructura persona (por medio del puntero)
   (*ptrPer).num = 548662; 
   (*ptrPer).calif= 9.8;
   strcpy((*ptrPer).nombre,"VAZQUEZ DELGADO CRISTIAN DE JESUS");

   //mostrando la estructura persona (por medio del puntero)
   mostrar(persona);

   return 0;
}

//Implementacion de las funciones
void mostrar(Datos persona){
   cout<<endl<<persona.num;
   cout<<endl<<persona.calif;
   cout<<endl<<persona.nombre;
}