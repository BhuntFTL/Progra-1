//_Procesamiento de imagen
//_Antonio Durón Mendoza y Tania Jaquelin López Acevedo
//_24/02/25
//_Est. de datos
#include <iostream>
using namespace std;
#define TAM 10
#define ROJO "\033[1;31m"  
#define AZUL "\033[1;34m"
#define COLOR_RESET "\033[0m"

void remplazar(int[][TAM]);
void mostrar(int[][TAM]);
void borrar(int[][TAM]);

int main(){
    int imagen[TAM][TAM]={0,0,0,0,0,0,0,0,0,0,
                          0,0,1,1,1,1,1,1,0,0,
                          0,1,1,1,1,1,1,1,1,0,
                          0,1,1,1,1,1,1,1,1,0,
                          0,1,1,1,0,0,1,1,1,0,
                          0,1,1,1,0,0,1,1,1,0,
                          0,1,1,1,1,1,1,1,1,0,
                          0,1,1,1,1,1,1,1,1,0,
                          0,0,1,1,1,1,1,1,0,0,
                          0,0,0,0,0,0,0,0,0,0};
    mostrar(imagen);
    remplazar(imagen);
    borrar(imagen);
    mostrar(imagen);
}

void mostrar(int imagen[][TAM]){
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            if(imagen[i][j]==1){
                cout<<ROJO<<imagen[i][j]<<COLOR_RESET<<" ";
            }else{
                cout<<AZUL<<imagen[i][j]<<COLOR_RESET<<" ";
            }
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void remplazar(int imagen[][TAM]){
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            if(imagen[i][j]==1){
                if(imagen[i-1][j-1]==0 ||imagen[i-1][j]==0 || imagen[i-1][j+1]==0 || imagen[i][j-1]==0 || imagen[i][j+1]==0 || imagen[i+1][j-1]==0 || imagen[i+1][j]==0 || imagen[i+1][j+1]==0){
                    imagen[i][j]=2;
                }
            }
        }
    }
}

void borrar(int imagen[][TAM]){
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            if(imagen[i][j]==2){
                imagen[i][j]=0;
            }
        }
    }
}