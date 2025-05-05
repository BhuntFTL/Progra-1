/*Mostrar las direcciones de memoria de un arreglo*/
#include <iostream>
using namespace std;
#define TAM 10
int main(int argvc, const char * argv[]){
    float vector[TAM]={1,2,3,4,5,6,7,8,9,10};

    cout<<"Direccion de memoria"<<endl;
    cout<<vector<<endl;

    cout<<"Direccion de memoria de cada posición"<<endl;
    for(int i=0; i<TAM; i++){
        cout<<&vector[i]<<endl;
    }
}