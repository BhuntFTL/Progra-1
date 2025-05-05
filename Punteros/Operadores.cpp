//Operadores & dirección y * indirección
#include <iostream>
using namespace std;

int main(){
    float calif=9.8, prom=0;
    float *ptrf=&calif;

    cout<<"direcc de mem de calif: "<<&calif<<endl;
    cout<<"valor de calif: "<<calif<<endl;

    cout<<"valor del lugar al que apunta ptrf: "<<*ptrf<<endl;
    cout<<"direcc de mem de ptrf: "<<&ptrf<<endl;
    cout<<"valor de calif: "<<ptrf<<endl;

    //Cambiar el valor de ptrf para qu apunte a prom
    ptrf=&prom;
    cout<<"valor de ptrf: "<<ptrf<<endl;
    cout<<"direcc de mem de ptrf: "<<&ptrf<<endl;
    cout<<"valor al que apunta ptrf: "<<*ptrf<<endl;

    //Modificar el valor de prom por medio del puntero
    *ptrf=10;
    cout<<prom<<endl;

    prom=9.7;
    cout<<*ptrf<<endl;

}