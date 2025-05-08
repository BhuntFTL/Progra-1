#include <iostream>
#include <stdlib.h>
#include <string.h>
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
Nodo capturaDatos();
void insertarNodos(Tlista&, Nodo);

int main(){
    menu();
}

void menu(){
    int opc;
    Nodo aux; //Aux es una estructura, no un puntero
    Tlista listaAlu; //Es un puntero de tipo nodo (struct Nodo *listaAlu)

    do{
        cout<<"LISTAS SIMPLES"<<endl;
        cout<<"Insertar nodos al inicio ....1"<<endl;
        cout<<"Recorrer/mostrar ............2"<<endl;
        cout<<"Eliminar ....................3"<<endl;
        cout<<"Salir .......................4"<<endl;
        cout<<"Tu opcion: ";
        cin>>opc;
        switch(opc){
            case 1: aux= capturaDatos();
                    insertarNodos(listaAlu, aux);
                    break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 5: break;
        }
    }while(opc!=6);
}

Nodo capturaDatos(){
    Nodo reg;
    cout<<"Nombre del alumno: ";
    cin>>reg.nombre;
    cout<<"Promedio del alumno: ";
    cin>>reg.prom;
    reg.ligaSig=NULL; //Este campo no se usa, por tanto se asigna como NULL o no se asigna nada
    return reg;
}

void insertarNodos(Tlista &lista, Nodo aux){
    Tlista alumno;
    //Crear un elemento para almacenar en la lista
    alumno= new(Nodo); //alumno= (Nodo*)malloc(1*sizeof(Nodo));
    strcpy(alumno->nombre, aux.nombre);
    alumno->prom = aux.prom;
    alumno->ligaSig = lista;
    lista = alumno;


}