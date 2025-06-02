//Grabar en archivos binarios - fread
#include <iostream>
using namespace std;

struct Hotel{
    int numHab;
    char nomHuesped[25];
    int dias;
    float costo;
    bool estado;
};

int main(){
    FILE *archHotel;
    Hotel huesped; //estructura para almacenar datos
    char resp;
    int posicion;
    archHotel=fopen("Huespedes.bin","rb");
    if(archHotel == NULL){
        cout<<"Error en archivo"<<endl;
        return 1;
    }
    cout<<"Que posicion? ";
    cin>>posicion;
    //leer datos
    fseek(archHotel, posicion * sizeof(Hotel), SEEK_SET);
    if(fread(&huesped,sizeof(Hotel),1,archHotel)){
        cout<<"Numero de habitación: "<<huesped.numHab<<endl;
        cout<<"Nombre del huesped: "<<huesped.nomHuesped<<endl;
        cout<<"Total a pagar: $"<<huesped.dias*huesped.costo<<endl;
    }else{
        cout<<"Habitacion no encontrada";
    }

    fclose(archHotel);
}