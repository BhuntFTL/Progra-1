//_Descomponer iterativo/recursivo
//_Antonio Durón Mendoza y Tania Jaquelin López Acevedo
//_24/02/25
//_Est. de datos
#include <bits/stdc++.h>
using namespace std;

void menu();
void iterar();
void recursar();

int main(){
    menu();
}
void menu(){
    int opc;
    do{
        cout<<"Elige una opcion:"<<endl;
        cout<<"1.- Iterativo"<<endl;
        cout<<"2.- Recursivo"<<endl;
        cin>>opc;
        switch(opc){
            case 1: iterar();
            case 2: recursar();
        }
    }while(opc!=3);
}
void iterar(){
    string num, temp;
    int total;
    int suma=0;
    int arreglo[total];
    cout<<"Que numero? ";
    cin>>num;
    total=num.length();
    for(int i=0; i<total; i++){
        temp=num[i];
        arreglo[i]=stoi(temp);
        suma=suma+arreglo[i];
        cout<<suma;
    }
    cout<<"La suma es: "<<suma<<endl;
}
void recursar(){
    
}