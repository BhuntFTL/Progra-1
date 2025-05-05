#include <iostream>
using namespace std;
#define TOT 4

enum Opciones{ALTAS=1, BAJAS, CONSULTAS, SALIR};
char opcTexto[][10]={"Altas","Bajas","Consultas","Salir"};

void menu();

int main(){
    menu();
}

void menu(){
    int opc=0;
    do{
        cout<<"MENU DE OPCIONES"<<endl;
        for(int i=0; i<TOT; i++){
            cout<<i+1<<".- "<<opcTexto[i]<<endl;
        }
        cin>>opc;
        switch(opc){
            case ALTAS: break;
            case BAJAS: break;
            case CONSULTAS: break;
        }
    }while(opc!=SALIR);
}