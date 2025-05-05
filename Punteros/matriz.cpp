#include <iostream>
#include <stdio.h>
#include <time.h>
#define TAM 10
#define REN 3
#define COL 3
using namespace std;

void llenar(int*);
void mostrar(int[]);
void llenarMat(int[][COL]);
void mostrarMat(int[][COL]);


int main(){
    srand(time(NULL));
    int vec[TAM];
    int mat[REN][COL];
    cout<<"direcc de num de vector: "<<vec<<endl;
    cout<<"direcc de num de vector: "<<&vec<<endl;
    cout<<"direcc de num de vector: "<<&vec[0]<<endl;
    llenar(vec);
    mostrar(vec);
    llenarMat(mat);
    mostrarMat(mat);
}

void llenar(int *vec){
    for(int i=0; i<TAM; i++){
        *(vec+i)=rand()%11;
    }
}

void mostrar(int vec[]){
    for(int i=0; i<TAM; i++){
        cout<<*(vec+i)<<"\t"<<(vec+1)<<endl;
    }
}

void llenarMat(int mat[][COL]){
    for(int i=0; i<REN; i++){
        for(int j=0; j<COL; j++){
            *(*(mat+i)+j)=rand()%11;
        }
    }
}

void mostrarMat(int mat[][COL]){
    for(int i=0; i<REN; i++){
        for(int j=0; j<COL; j++){
            cout<<*(*(mat+i)+j)<<"---"<<((mat+i)+j)<<"\t";
        }
        cout<<endl;
    }
}
