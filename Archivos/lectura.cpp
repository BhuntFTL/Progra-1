//Archivos de texto - Leer datos
#include <iostream>
using namespace std;

int main(){
    //Declarar archivo
    FILE *archTxt; //Variable par manejar el archivo
    int id;
    float prom;
    char *nombre= new char[25], resp;

    //Abrir archivo
    archTxt= fopen("alumnos.txt","r");
    //Verificar apertura
    if(!archTxt){ //Si el archivo no se puede abrir
        cout<<"Error de letura!";
        return 1;
    }
    //Si se puede abrir contunuamos
    cout<<"Contenido del archivo: "<<endl;
    //Mientras no sea fin de archivo
    while(!feof(archTxt)){
        //Sacar datos del archivo;
        fscanf(archTxt,"%d\t%s\t%f\n", &id, nombre, &prom);
        cout<<id<<"\t"<<nombre<<"\t"<<prom<<endl;
    }

    //Cerrar archivo
    fclose(archTxt);
}
    