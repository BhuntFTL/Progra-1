#include <iostream>
#include <string.h>
using namespace std;

struct Fecha{
    int dd,aa;
    char mm[10];   //mes con letras
};

struct Estado{
    char soltero;   //S
    char viudo;     //V
    char casado;    //C
};

struct Persona{
    int dni;
    char nombre[25];
    Estado edoCivil;
    Fecha fechaNac;
};

enum Mes{ENE=1,FEB,MAR,ABR,MAY,JUN,JUL,AGO,SEP,OCT,NOV,DIC};

void capturarInfo(Persona &);   //Por referencia
void mostrarInfo(Persona);      //Por valor
char capturaEdo();              //Devuelve 1 char

int main(){
    Persona tito;
    capturarInfo(tito);
    mostrarInfo(tito);
}

void capturarInfo(Persona &tito){
    char estado;
    cout<<"CAPTURA DE DATOS"<<endl;
    cout<<"DNI: ";
    cin>>tito.dni;
    cout<<"Nombre: ";
    cin>>tito.nombre;
    estado=capturaEdo();
    switch(estado){
        case 'S': tito.edoCivil.soltero='S'; break;
        case 'V': tito.edoCivil.viudo='V'; break;
        case 'C': tito.edoCivil.casado='C'; break;
        default: tito.edoCivil.soltero='S';
    }
    cout<<"Fecha de nacimiento"<<endl;
    cout<<"Dia (dd): ";
    cin>>tito.fechaNac.dd;
    cout<<"Mes: ";
    cin>>tito.fechaNac.mm;
    cout<<"Anio (aa): ";
    cin>>tito.fechaNac.aa;

}

char capturaEdo(){
    char edo;
    cout<<"Estado Civil: ";
    cin>>edo;
    if (edo=='S')
        return edo;
    if (edo=='V')
        return edo;
    if (edo=='C')
        return edo;
    return 'Z';
}

void mostrarInfo(Persona tito){
    cout<<"DATOS DE LA PERSONA"<<endl;
    cout<<"DNI: "<<tito.dni<<endl;
    cout<<"Nombre: "<<tito.nombre<<endl;
    cout<<"Estado civil"<<endl;
    switch(tito.edoCivil.casado){
        case 'S': cout<<"Soltero"<<endl; break;
        case 'V': cout<<"Viudo"<<endl; break;
        case 'C': cout<<"Casado"<<endl; break;
    }
    cout<<"Fecha de nacimiento"<<endl;
    //PENDIENTE POR RESOLVER
}