#include <iostream>
using namespace std;
#define TAM 5

struct fecha{
    int dd,mm,aa;
};

struct Carro{
    int numSerie;
    float precio;
    fecha fechaProd;
};

void menu();
void captura(Carro[]);
int capturarNum();
Carro busqueda(int, Carro[]);
void mostrar(Carro);
void ordenar(Carro[]);

int main(){
    menu();
}

void menu(){
    int opc, numeroS;
    Carro registro, coches[TAM];
    do{
        cout<<"ARREGLOS DE ESTRUCTURAS"<<endl;
        cout<<"1.- Captura"<<endl;
        cout<<"2.- Búsqueda"<<endl;
        cout<<"3.- Ordenación"<<endl;
        cout<<"Opción: "<<endl;
        cin>>opc;
        switch(opc){
            case 1: captura(coches); break;
            case 2: numeroS=capturarNum();
                    registro=busqueda(numeroS,coches); 
                    mostrar(registro); break;
            case 3: ordenar(coches); break;
        }
    }while(opc!=4);
}

void captura(Carro coches[]){
    cout<<"Captura de datos"<<endl;
    for(int i=0; i<TAM; i++){
        cout<<"Numero de serie: ";
        cin>>coches[i].numSerie;
        cout<<"Precio: ";
        cin>>coches[i].precio;
        cout<<"Fecha de produccion"<<endl;
        cout<<"Día:";
        cin>>coches[i].fechaProd.dd;
        cout<<"Mes:";
        cin>>coches[i].fechaProd.mm;
        cout<<"Año:";
        cin>>coches[i].fechaProd.aa;

    }
}

int capturarNum(){
    int num=0;
    cout<<"Número de serie a buscar:";
    cin>>num;
    return num;
}

Carro busqueda(int numeroS, Carro coches[]){
    Carro aux;
    aux.numSerie=-1;
    for(int i=0; i<TAM; i++){
        if(numeroS==coches[i].numSerie){
            aux=coches[i];
            break;
        }
    }
    return aux;
}

void mostrar(Carro registro){
    if(registro.numSerie==-1){
        cout<<"No se encontró"<<endl;
    }else{
        cout<<"Numero de serie: "<<registro.numSerie<<endl;
        cout<<"Precio: "<<registro.precio<<endl;
        cout<<"Fecha de produccion"<<endl;
        cout<<"Día: "<<registro.fechaProd.dd<<endl;
        cout<<"Mes: "<<registro.fechaProd.mm<<endl;
        cout<<"Año: "<<registro.fechaProd.aa<<endl;
    }
}

void ordenar(Carro coches[]){
    Carro temp;
    for(int i=0; i<TAM;i++){
        for(int j=0; j<TAM-1; j++){
            if(coches[j].precio>coches[j+1].precio){
                temp=coches[j];
                coches[j]=coches[j+1];
                coches[j+1]=temp;
            }
        }
    }
    for(int i=0; i<TAM; i++){
        mostrar(coches[i]);
        cout<<endl<<endl;
    }
}