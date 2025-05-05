/* Imprimir una pirámide de dígitos como la de la figura, tomando como 
entrada el número de filas de la misma*/

#include <iostream>
using namespace std;

void piramide(int);

int main(){
    int filas=0;
    cout<<"Filas: ";
    cin>>filas;
    piramide(filas);
}

void piramide(int filas){
    for(int i=1; i<filas+1; i++){
        for(int h=filas; h>i; h--){
            cout<<"\t";
        }
        for(int j=1; j<=i; j++){
            cout<<j<<"\t";
        }
        for(int k=i-1; k>=1; k--){
            cout<<k<<"\t";
        }
        cout<<endl;
        
    }
}