#include <iostream>
#include <stdlib.h>
#include <time.h>
#define REN 4
#define COL 4
using namespace std;

int **crearMatriz();
void llenar(int **);
void mostrar(int **);
int sumatoria(int **);

int main(){
    srand(time(NULL));
    int **matriz;
    matriz= crearMatriz();
    llenar(matriz);
    mostrar(matriz);
    cout<<"SUMA DE LA X: "<<sumatoria(matriz)<<endl;
}

int **crearMatriz(){
    int **aux;
    aux= (int**)calloc(REN,sizeof(int));
    for(int i=0; i<REN; i++){
        aux[i]= (int*)calloc(COL,sizeof(int));
    }
    return aux;
}

void llenar(int **matriz){
    for(int i=0; i<REN; i++){
        for(int j=0; j<COL; j++){
            matriz[i][j]=rand()%21;
        }
    }

}

void mostrar(int **matriz){
    for(int i=0; i<REN; i++){
        for(int j=0; j<COL; j++){
            cout<<matriz[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int sumatoria(int **matriz){
    int suma=0;
    for(int i=0; i<REN; i++){
        for(int j=0; j<COL; j++){
            if(i==j){
                suma+=matriz[i][j];
            }
        }
    }
    for(int i=0; i<REN; i++){
        for(int j=COL-1; j>=0; j--){
            if(i+j==3){
                suma+=matriz[i][j];
            }
        }
    }
    return suma;
}