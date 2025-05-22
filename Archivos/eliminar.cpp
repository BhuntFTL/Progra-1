/*Archivos de tecto - Eliminar
Eliminar registros de un archivo combina la 
lectura y escritura en dos archivos*/

#include <iostream>
using namespace std;

void eliminar(int, FILE*, FILE*);

int main(){
    //1.-Declarar archivo origen y temporal
    FILE *archTxt, *archTemp;
    int borrar;
    cout<<"Dame el id para eliminar: ";
    cin>>borrar;

    eliminar(borrar, archTxt, archTemp);
}

void eliminar(int borrar, FILE *archTxt, FILE *archTemp){
    int id;
    float prom;
    char *nombre= new char[25];

    //Abrir archivo origen para lectura
    archTxt= fopen("alumnos.txt","r");
    archTemp= fopen("temporal.txt","w");

    //mover datos que se van a conservar a temporal
    //leer datos
    while(!feof(archTxt)){
        //Sacar datos del archivo;
        fscanf(archTxt,"%d\t%s\t%f\n", &id, nombre, &prom);
        //comparar con el que se eliminará, si no es el de borrar se copia en temp
        if(id!=borrar){
            //grabar datos en temporal
            fprintf(archTemp,"%d\t%s\t%f\n", id, nombre, prom);
        }
    }
    //Cerrar archivos
    fclose(archTxt);
    fclose(archTemp);

    //Eliminar archivo origen y renovar el temporal
    remove("alumnos.txt");
    rename("temporal.txt","alumnos.txt");
    delete nombre; 
}