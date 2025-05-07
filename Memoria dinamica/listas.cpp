#include <iostream>
#include <stdlib.h>
using namespace std;

//Declarar la estructura para al,acenar los nodos
struct Nodo{
    char nombre[15];
    float prom;
    Nodo *ligaSig;
};

typedef struct Nodo *Tlista;
/*T lista es un alias para un puntero de tipo Nodo, esto significa que en lugar
de escribir (struct Nodo *elemento) para poder declarar una variable de tipo puntero a una
estructura, solo pondremos (Tlista elemento) y con eso resumimos el codigo*/

void menu();

int main(){
    menu();
}

void menu(){
    int opc;
    do{
        cout<<"LISTAS SIMPLES"<<endl;
        cout<<"Insertar nodos al inicio ....1"<<endl;
        cout<<"Recorrer/mostrar ............2"<<endl;
        cout<<"Eliminar ....................3"<<endl;
        cout<<"Salir .......................4"<<endl;
        cout<<"Tu opcion: ";
        cin>>opc;
        switch(opc){
            case 1: break;
            case 2: break;
            case 3: break;
        }
    }
}