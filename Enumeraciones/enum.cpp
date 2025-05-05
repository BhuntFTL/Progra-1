//Enumeraciones
/*Son un conjunto de constantes*/
#include <iostream>
using namespace std;

enum Colores{ROJO=5, VERDE, AZUL=9, CAFE, AMARILLO};

void mostrarColor(Colores);

int main(){
    Colores colorPref; //variable tipo enumeración
    colorPref=ROJO;
    mostrarColor(colorPref);
}

void mostrarColor(Colores colorPref){
    switch(colorPref){
        case AZUL: cout<<"Azul"<<endl; break;
        case ROJO: cout<<"Rojo"<<endl; break;
        case VERDE: cout<<"Verde"<<endl; break;
        case CAFE: cout<<"Cafe"<<endl; break;
        case AMARILLO: cout<<"Amarillo"<<endl; break;
    }
}