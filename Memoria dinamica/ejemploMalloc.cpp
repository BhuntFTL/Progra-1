/*
MEMORIA DINAMICA

    ANSI C <stdio.h>

    - malloc:
        Asigna memoria dinámica y devuelve un puntero al primer elemento. Se caracteriza
        por inicializar los elementos.

        Sintaxis vector:
        varPtr= (tipoDato*)malloc(tam*sizeof(tipoDato));

        Ejemplo vector: crear un vector para almacenar 5 calificaciones
        float *calif;
        Asignar memoria: calirf=(float*)malloc(5*sizeof(float));

        Sintaxis matriz:
        matriz= (tipoDato**)malloc(REN*sizeof(tipoDato));
        for(int i=0; i<REN; i++){
            matriz[i]= (tipoDato*)malloc(COL*sizeof(tipoDato));
        }

    - calloc:
        Asigna memoria dinámica y devuelve un puntero al primer elemento. No inicializa
        elementos.

        Sintaxis:
        varPtr= (tipoDato*)calloc(tam,sizeof(tipoDato));

        Ejemplo: crear una variable para almacenar una cadena
        char *cadena;
        Asignar memoria: cadena=(char*)calloc(25,sizeof(tipoDaro));

        Sintaxis matriz:
        matriz= (tipoDato**)calloc(REN,sizeof(tipoDato));
        for(int i=0; i<REN; i++){
            matriz[i]= (tipoDato*)calloc(COL,sizeof(tipoDato));
        }

    C++ <iostream>

    - new:
        Asigna memoria dinámica y devuelve un puntero al primer elemento. Se caracteriza por
        inicializar todos los elementos.

        Sintaxis:
        varPtr= new tipoDato;
        
        Ejemplo: reservar memoria para una variable que almacena edades
        int *edades;
        edades= new(tipoDato);
        edades= new tipoDato[cantidad];

LIBERAR MEMORIA

    ANSI C <stdio.h>

        free(varPtr);
    
    C++ <iostream>

        delete varPtr;

*/

//Arreglo dinámico con malloc, calloc y new

#include <iostream>
#include <stdlib.h>
#include <time.h>
#define TAM 10
using namespace std;

int *captura();
void mostrar(int *);

int main(){
    int *vec; //Puntero tipo entero
    //Reservar memoria de tamaño TAM para el vector
    vec= (int*)malloc(TAM*sizeof(int));
    vec= captura();
    mostrar(vec);
    cout<<"\nDirección de vec: "<<vec<<endl;
    free(vec);
    //Con esto verificamos si se libero la memoria
    cout<<"Dirección de vec: "<<vec<<endl;
    mostrar(vec);
}

int *captura(){
    int *aux;
    aux= (int*)malloc(TAM*sizeof(int));
    for(int i=0; i<TAM; i++){
        aux[i]=rand()%11;
        // (*(aux+i))=rand()%11;
    }
    return aux;
}

void mostrar(int *vec){
    for(int i=0; i<TAM; i++){
        cout<<(*(vec+i))<<"\t";
        // cout<<vec[i]<<"\t";
    }
}

