/*Operaciones con matrices: suma, mult. po run escalar,
mult de matrices, traspuesta*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define REN 4
#define COL 3
#define TAM 3

void menu(int[][COL], int[][COL]);
void llenar(int[][COL], int, int);
void mostrarMat(int[][COL], int, int);
void sumaMat(int[][COL], int[][COL], int[][COL]);
void multEsc(int[][COL], int);
void trans();

int main(){
    srand(time(NULL));
    int matA[REN][COL], matB[REN][COL];
    llenar(matA,REN,COL);
    llenar(matB,REN,COL);
    menu(matA,matB);    
}

void menu(int matA[][COL],int matB[][COL]){
    int matSuma[REN][COL], escalar=0, opc=0;
    do{
        cout<<"OPERACIONES CON MATRICES\n";
        cout<<"Suma de matrices........1\n";
        cout<<"Mult. * escalar.........2\n";
        cout<<"Mult. de matrices.......3\n";
        cout<<"Transpuesta.............4\n";
        cout<<"Salir...................5\n";
        cin>>opc;
        switch(opc){
            case 1: sumaMat(matA,matB,matSuma);
                    mostrarMat(matA,REN,COL);
                    mostrarMat(matB,REN,COL);
                    mostrarMat(matSuma,REN,COL);
                    break;
            case 2: cout<<"Valor escalar: ";
                    cin>>escalar;
                    multEsc(matSuma,escalar);
                    break;
            case 4: trans();
        }

    }while(opc!=5);
}

void llenar(int matriz[][COL], int filas, int columnas){
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            matriz[i][j]=rand()%10;
        }
    }
}

void mostrarMat(int matriz[][COL], int filas, int columnas){
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            cout<<matriz[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void sumaMat(int matA[][COL], int matB[][COL], int matSuma[][COL]){
    for (int i = 0; i < REN; i++){
        for(int j=0; j<COL; j++){
            matSuma[i][j]=matA[i][j]+matB[i][j];
        }
    }
}

void multEsc(int matSuma[][COL], int escalar){
    int matRes[REN][COL]; //almacenar resultado
    for(int i=0; i<REN; i++){
        for(int j=0; j<COL; j++){
            matRes[i][j]=matSuma[i][j]*escalar;
        }
    }
    mostrarMat(matRes,REN,COL);
}

void trans(){
    int matriz[REN][COL], matrizT[COL][REN];
    llenar(matriz,REN,COL);
    for(int i=0; i<COL; i++){
        for(int j=0; j<REN; j++){
            matrizT[j][i]=matriz[i][j];
            cout<<matrizT[j][i]<<"\t";
        }
        cout<<"\n";
    }

}

