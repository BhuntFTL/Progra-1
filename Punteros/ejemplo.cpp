/*Uso del operador de dirección & y de indirección * */
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]){
    int dato=15, *ptrI=NULL, otra=9;
    float calif, *ptrf;

    ptrI=&dato; //"ptr" apunta o guarda la dirección de "dato"

    cout<<"Contenido de dato y ptr"<<endl;
    cout<<"dato: "<<dato<<endl;
    cout<<"ptrI: "<<ptrI<<endl;

    cout<<"Contenido de dato y ptr"<<endl;
    cout<<"&dato: "<<&dato<<endl;
    cout<<"&ptrI: "<<&ptrI<<endl;

    cout<<"Contenido de dato y ptr"<<endl;
    cout<<"*ptrI: "<<*ptrI<<endl;

    ptrI=&otra;
    cout<<"\nContenido de dato y ptr"<<endl;
    cout<<"*ptrI: "<<*ptrI<<endl;

    *ptrI=20;
    cout<<"\nContenido de dato y ptr"<<endl;
    cout<<"*ptrI: "<<*ptrI<<endl;
    cout<<"otra: "<<otra<<endl;


}