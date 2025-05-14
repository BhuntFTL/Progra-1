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
void mostrar(Tlista);
void contar(Tlista);
void promedio(Tlista);

int main(){
    menu();
}

void menu(){
    int opc;
    Nodo aux; //Aux es una estructura, no un puntero
    Tlista listaAlu=NULL; //Es un puntero de tipo nodo (struct Nodo *listaAlu)

    do{
        cout<<"LISTAS SIMPLES"<<endl;
        cout<<"Insertar nodos al inicio ............1"<<endl;
        cout<<"Mostrar .............................2"<<endl;
        cout<<"Numero con prom de 8.5 o más ........4"<<endl;
        cout<<"Promedio grupal .....................5"<<endl;
        cout<<"Salir ...............................6"<<endl;
        cout<<"Tu opcion: ";
        cin>>opc;
        switch(opc){
            case 1: aux= capturaDatos();
                    insertarNodos(listaAlu, aux);
                    break;
            case 2: mostrar(listaAlu);
                    break;
            case 4: contar(listaAlu);
                    break;
            case 5: promedio(listaAlu);
                    break;
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

void mostrar(Tlista lista){
    Tlista aux=lista;
    while(aux!=NULL){
        cout<<"Nombre: "<<aux->nombre<<endl;
        cout<<"Prom: "<<aux->prom<<endl;
        aux=aux->ligaSig;
    }
}

void contar(Tlista lista){
    Tlista aux=lista;
    int cont=0;
    while((aux->prom)>=8.5){
        cont++;
    }
    cout<<"La cantidad de alumnos con promedio de 8.5 o superior es: "<<cont<<endl;
}

void promedio(Tlista lista){
    Tlista aux=lista;
    float suma=0, promedio=0;
    int cont=0;
    while(aux!=NULL){
        suma+=(aux->prom);
        cont++;
    }
    promedio=suma/cont;
    cout<<"El promedio de todo el grupo es de: "<<promedio<<endl;
}
