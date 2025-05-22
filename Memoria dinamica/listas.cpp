#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//Declarar la estructura para almacenar los nodos
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
void eliminarPrimero(Tlista&);
void busquedaPromedio(Tlista, int);
void eliminarNombre(Tlista&, char[]);
void ordenarPorPromedio(Tlista&);
Tlista insertarOrdenado(Tlista, Tlista);

int main(){
    menu();
}

void menu(){
    int opc, promedio;
    char nombre[25];
    Nodo aux; //Aux es una estructura, no un puntero
    Tlista listaAlu=NULL; //Es un puntero de tipo nodo (struct Nodo *listaAlu)

    do{
        cout<<"LISTAS SIMPLES"<<endl;
        cout<<"Insertar nodos al inicio ............1"<<endl;
        cout<<"Recorrer/mostrar ....................2"<<endl;
        cout<<"Eliminar al inicio ..................3"<<endl;
        cout<<"Busqueda por Promedio ...............4"<<endl;
        cout<<"Eliminar un nodo (por nombre)........5"<<endl;
        cout<<"Ordenar y mostrar (por promedio) ....6"<<endl;
        cout<<"Salir ...............................7"<<endl;
        cout<<"Tu opcion: ";
        cin>>opc;
        switch(opc){
            case 1: aux= capturaDatos();
                    insertarNodos(listaAlu, aux);
                    break;
            case 2: mostrar(listaAlu);
                    break;
            case 3: eliminarPrimero(listaAlu);
                    break;
            case 4: cout<<"Dame el promedio de quien buscar: "<<endl;
                    cin>>promedio;
                    busquedaPromedio(listaAlu, promedio);
                    break;
            case 5: cout<<"Dame el nombre de quien eliminar: "<<endl;
                    cin>>nombre;
                    eliminarNombre(listaAlu, nombre);
                    break;
            case 6: ordenarPorPromedio(listaAlu);
                    mostrar(listaAlu);
                    break;
            case 7: break;
        }
    }while(opc!=7);
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

void eliminarPrimero(Tlista &lista){
    Tlista temp=lista; //almacena el nodo a eliminar y hacemos que apunte a lo que apunte lista
    if(lista!=NULL){ //Si apunta a un valor
        lista=lista->ligaSig; //Desconecta el elemento a eliminar
        delete temp; //Borra el elemento a eliminar
    }else{ //No apunta a un valor
        cout<<"Lista vacía!!!"<<endl;
    }
}

void busquedaPromedio(Tlista lista, int promedio){
    bool encontrado = false;
    while(lista!=NULL){
        if(lista->prom==promedio){
            cout<<"Encontrado:"<<endl;
            cout<<"Nombre: "<<lista->nombre<<endl;
            cout<<"Prom: "<<lista->prom<<endl;
            encontrado = true;
        }
        lista=lista->ligaSig;
    }
    if(!encontrado){
        cout<<"No encontrado"<<endl;
    }
}

void eliminarNombre(Tlista &lista, char nombre[]){
    Tlista actual = lista;
    Tlista anterior = NULL;
    
    while(actual != NULL){
        if(strcmp(actual->nombre, nombre) == 0){
            if(anterior == NULL){ // Es el primer nodo
                lista = actual->ligaSig;
            } else {
                anterior->ligaSig = actual->ligaSig;
            }
            delete actual;
            cout<<"Nodo eliminado correctamente."<<endl;
            return;
        }
        anterior = actual;
        actual = actual->ligaSig;
    }
    cout<<"No se encontro el nombre en la lista."<<endl;
}

void ordenarPorPromedio(Tlista &lista){
    if (lista == NULL || lista->ligaSig == NULL){
        return;
    }

    Tlista listaOrdenada = NULL;
    Tlista actual = lista;
    Tlista siguiente;

    while (actual != NULL){
        siguiente = actual->ligaSig;
        listaOrdenada = insertarOrdenado(listaOrdenada, actual);
        actual = siguiente;
    }
    lista = listaOrdenada;
}

Tlista insertarOrdenado(Tlista lista, Tlista nuevoNodo){
    if (lista == NULL || nuevoNodo->prom <= lista->prom){
        nuevoNodo->ligaSig = lista;
        return nuevoNodo;
    }

    Tlista actual = lista;
    while (actual->ligaSig != NULL && actual->ligaSig->prom < nuevoNodo->prom){
        actual = actual->ligaSig;
    }

    nuevoNodo->ligaSig = actual->ligaSig;
    actual->ligaSig = nuevoNodo;
    return lista;
}