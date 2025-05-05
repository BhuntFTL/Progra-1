//Operaciones básicas con matrices
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define REN 5
const int COL=5;

void llenarMat(char[][COL]); //Llenar matriz
int mostrarMat(char[][COL]); //Mostrar matriz y devolver el numero de veces que encontro la vocal i
bool buscarLetra(char[][COL], char); //Buscar caracter puesto y devlver si lo encontro o no
void modificarMat(char[][COL]); //Modificar la matriz con vocales y numeros
void mostrar(char[][COL]); //Solo mostrar

int main(){
    srand(time(NULL));
    char matriz[REN][COL], letra;
    int totalI=0;
    bool encontrado=false;
    
    //Llamadas a funciones
    llenarMat(matriz);
    
    //mostrarMat devuelve el total de i encontrado
    totalI=mostrarMat(matriz);
    cout<<"Total de i: "<<totalI<<endl;
    
    //solicita la letra a buscar
    cout<<"Letra a buscar: ";
    cin>>letra;
    
    //busca la letra 
    encontrado=buscarLetra(matriz,letra);
    if(encontrado){
        cout<<"Letra encontrada!\n";
    }else{
        cout<<"La letra no se encontro ;(\n";
    }
    
    //Modifica la matriz
    modificarMat(matriz);
    totalI=mostrarMat(matriz);

} 

//Aleatorios en un rango de valores valor=(rand()%(MAX-MIN+1));
void llenarMat(char matriz[][COL]){
    for(int i=0; i<REN; i++){
        for(int j=0; j<COL; j++){
            matriz[i][j]=(char)(rand()%26+'a');
        }
    }
}

int mostrarMat(char matriz[][COL]){
    int totalI=0;
    for(int i=0; i<REN; i++){
        for(int j=0; j<COL; j++){
            cout<<matriz[i][j]<<"\t";
            if (matriz[i][j]=='i'){
                totalI++;
            }
        }
        cout<<"\n";
    }
    return totalI;
}

bool buscarLetra(char matriz[][COL], char letra){
    bool existe=false;
    for(int i=0; i<REN; i++){
        for(int j=0; j<COL; j++){
            if (matriz[i][j]==letra){
                existe=true;
                break;
            }
        }
    }
    return existe;
}

void modificarMat(char matriz[][COL]){
    //Convertir a-4, e-3, i-1 o-0
    for(int i=0; i<REN; i++){
        for(int j=0; j<COL; j++){
            switch(matriz[i][j]){
                case 'a': matriz[i][j]=='4'; break;
                case 'e': matriz[i][j]=='3'; break;
                case 'i': matriz[i][j]=='1'; break;
                case 'o': matriz[i][j]=='0'; break;
            }
        }
    }
}








