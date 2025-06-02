//Grabar en archivos binarios - fwrite
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
    archHotel=fopen("Huespedes.bin","ab");
    if(archHotel == NULL){
        cout<<"Error en archivo"<<endl;
        return 1;
    }
    //capturar datos
    do{
        cout<<"Numero de habitación: ";
        cin>>huesped.numHab;
        cout<<"Nombre del huesped: ";
        cin>>huesped.nomHuesped;
        cout<<"Dias de hospedaje: ";
        cin>>huesped.dias;
        cout<<"Costo por dia: $";
        cin>>huesped.costo;
        huesped.estado= true; //indica que está activo
        /*  -Referencia de la estructura
            -Tamaño de la estrcutura
            -Valor 1
            -Variable de tipo archivo     */
        fwrite(&huesped, sizeof(Hotel), 1, archHotel);
        cout<<"Continuar s/n? ";
        cin>>resp;
        
    }while(resp != 'n');

    fclose(archHotel);
}