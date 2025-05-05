//Manejo de estructuras simples
#include <iostream>
#include <string.h>
using namespace std;

/*DECLARAR ESTRUCTURA*/
struct Alumno{      //Las estructuras no inicializan sus campos
    int id;         //Los campos no se pueden acceder sin
    char nom[20];   //una variable tipo struct
    float calif[4];
    char grupo;
}luis;

void limpiar(Alumno&);
void mostrar(Alumno);

int main(){
    //variable tipo struct sin inicializar
    Alumno pepon; 
    
    //variable tipo struct inicializada
    Alumno ana={0," ",{0,0,0,0},' '};
    
    //variable inicializada con una funcion
    Alumno tito;
    limpiar(tito);
    mostrar(tito);
}

void limpiar(Alumno &tito){
    tito.id=0;
    strcpy(tito.nom,"Tito");
    tito.grupo='A';
    for(int i=0; i<4; i++){
        tito.calif[i]=i*3;
    }
}
void mostrar(Alumno tito){
    cout<<"ID: "<<tito.id<<endl;
    cout<<"Nombre: "<<tito.nom<<endl;
    cout<<"Grupo"<<tito.grupo<<endl;
    for(int i=0; i<4; i++){
        cout<<"Cal: "<<tito.calif[i]<<endl;
    }
}