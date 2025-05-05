/*
 	Clase del 2 de abril del 2025
 	
 	Apuntando a un vector

	Tomando el mismo ejercicio #23
 
 */

 #include<iostream>
 #include<stdlib.h>
 #include<time.h>
 using namespace std;
 
 //Datos
 #define TAM 10
 
 //Prototipo de funciones
 void llenar(int*);
 void mostrar(int*);

 //Programa principal
 int main(){
    srand(time(NULL));
 	int vec[TAM];

	llenar(vec);
	mostrar(vec);

	return 0;
 }
 
 //Implementacion de funciones
  void llenar(int *vec){
  	for(int i=0; i<TAM; i++){
		*(vec+i)=rand()%11;
	}
  }
 
 void mostrar(int *vec){
    //Puntero que apunte a vec
    int *ptrI= &vec[0];

    cout<<endl<<"VECTOR (NOTACION DE ARREGLOS): "<<"\t\t";
	for(int i=0; i<TAM; i++){
		cout<< vec[i]<<"\t";
	}
    
    cout<<endl<<"VECTOR (NOTACION DE PUNTEROS): "<<"\t\t";
	for(int i=0; i<TAM; i++){
		cout<<*(vec+i)<<"\t";
	}

    cout<<endl<<"PUNTERO (NOTACION DE ARREGLOS): "<<"\t";
	for(int i=0; i<TAM; i++){
		cout<<ptrI[i]<<"\t";
	}

    cout<<endl<<"PUNTERO (NOTACION DE PUNTEROS): "<<"\t";
	for(int i=0; i<TAM; i++){
		cout<<*(ptrI+i)<<"\t";
	}
 }