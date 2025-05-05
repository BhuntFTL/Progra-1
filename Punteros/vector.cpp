#include <iostream>
#include <stdio.h>
#include <time.h>
#define TAM 10
using namespace std;

void llenar(int*);
void mostrar(int*);

int main(){
    srand(time(NULL));
    int vec[TAM];
    cout<<"direcc de num de vector: "<<vec<<endl;
    cout<<"direcc de num de vector: "<<&vec<<endl;
    cout<<"direcc de num de vector: "<<&vec[0]<<endl;
    llenar(vec);
    mostrar(vec);
}

void llenar(int *vec){
    for(int i=0; i<TAM; i++){
        *(vec+i)=rand()%11;
    }
}

void mostrar(int vec[]){
    for(int i=0; i<TAM; i++){
        cout<<*(vec+i)<<"\t"<<&vec[i]<<endl;
    }
}
