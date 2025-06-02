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
    archHotel=fopen("Huespedes.bin","rb");
    if(archHotel == NULL){
        cout<<"Error en archivo"<<endl;
        return 1;
    }
    //leer datos
    while(fread(&huesped, sizeof(Hotel), 1, archHotel)){
        if(huesped.estado){
            cout<<"Numero de habitación: "<<huesped.numHab<<endl;
            cout<<"Nombre del huesped: "<<huesped.nomHuesped<<endl;
            cout<<"Dias de hospedaje: "<<huesped.dias<<endl;
            cout<<"Costo por dia: $"<<huesped.costo<<endl<<endl;
        }
    }

    fclose(archHotel);
}