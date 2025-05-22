/*
    1.- Escribir una función que reciba una matriz (con datos) y un vector (vacío)
    La matriz se debe convertir a vector
    
    2.- Escribir una función que reciba una matriz (con datos) y muestre solo el marcode la matriz.
    Debe devolver el total de valores mostrados
    
    3.- Escribir una función que reciba una matriz char (con datos) y la convierta de la siguiente forma:
            -Vocales ---> #
            -Consonantes ---> 0
            -Total de vocales y consonantes convertidas
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define TAM 4

void llenar(int[][TAM]);
void llenar2(char[][TAM]);
void conVector(int[][TAM], int[]);
void marco(int[][TAM]);
void convertir(char[][TAM]);

int main(){
    srand(time(NULL));
    int matriz[TAM][TAM], vector[TAM*TAM], opcion;
    char matriz2[TAM][TAM];
    llenar(matriz);
    llenar2(matriz2);
    do{
        cout<<"Opción:\n"<<"1.- Matriz a vector\n"<<"2.- Marco matriz\n"<<"3.- Transformar\n"<<"4.- Salir\n";
        cin>>opcion;
        switch (opcion){
            case 1: conVector(matriz,vector); break;
            case 2: marco(matriz); break;
            case 3: convertir(matriz2); break;
        }
    }while(opcion!=4);
}

void llenar(int matriz[][TAM]){
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            matriz[i][j]=rand()%20;
        }
    }
    cout<<"Aquí está: \n";
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            cout<<matriz[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

void llenar2(char matriz[][TAM]){
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            matriz[i][j]=(char)(rand()%26+'a');
        }
    }
    cout<<"Aquí está: \n";
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            cout<<matriz[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

void conVector(int matriz[][TAM], int vector[TAM*TAM]){
    int k=0;
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            vector[k]=matriz[i][j];
            k++;
        }
    }
    cout<<"Tu vector:\n";
    for(int l=0; l<k; l++){
        cout<<vector[l]<<"\t";
    }
}

void marco(int matriz[][TAM]){
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            if (i==0 || i==(TAM-1) || j==0 || j==(TAM-1)){
                cout<<matriz[i][j]<<"\t";
            }else{
                cout<<"\t";
            }
        }
        cout<<"\n";
    }
}

void convertir(char matriz2[][TAM]){
    int totalVocales=0;
    int totalConsonantes=0;
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            char c = tolower(matriz2[i][j]);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                matriz2[i][j] = '#';
                totalVocales++;
            }else{
                matriz2[i][j] = '0';
                totalConsonantes++;
            }
        }
    }
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            cout<<matriz2[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"Total de vocales convertidas: " << totalVocales << "\n";
    cout<<"Total de consonantes convertidas: " << totalConsonantes << "\n";

}
