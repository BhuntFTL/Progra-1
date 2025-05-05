//Manejo de uniones
#include <iostream>
using namespace std;

/*Una union almacena solo un dato a la vez, si se
guarda un valor diferente,el valor actual se pierde*/
struct Fecha{
    int dd, mm, aa;
}

union Refresco{
    int codigo;
    char nombre[25];
    float precio;
    Fecha fechaProd;
};

void capturaUnion(Refresco &);
void tamano(Refresco);

int main(){
    Refresco soda; //soda es una variable de tipo union
    capturaUnion(soda);

}

void capturaUnion(Refresco &soda){
    cout<<"Código: ";
    cin<<soda.codigo;
    cout<<"Nombre: ";
    cin>>soda.nombre;
    cout<<"Precio: ";
    cin>>soda.precio;
    cout<<"Fecha: ";
    cin>>soda.fechaProd.dd;
    soda.fechaProd.mm=3;
    soda.fechaProd.aa=2000;
    cout<<soda.codigo<<"\t"<<soda.nombre<<"\t"<<soda.precio;
}

void tamano(Refresco soda){
    
}