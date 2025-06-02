/*Archivos de texto - Cambios */

#include <iostream>
using namespace std;

void cambios(int, FILE*, FILE*);

int main(){
    //1.-Declarar archivo origen y temporal
    FILE *archTxt, *archTemp;
    int idC;
    cout<<"Dame el id para cambiar sus datos: ";
    cin>>idC;

    cambios(idC, archTxt, archTemp);
}

void cambios(int idC, FILE *archTxt, FILE *archTemp){
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
        //comparar con el que se cambiará, si no es el de cambiar se copia en temp
        if(id!=idC){
            //grabar datos en temporal
            fprintf(archTemp,"%d\t%s\t%f\n", id, nombre, prom);
        }else{
            //registrar nuevos datos sin cambiar id
            cout<<"NOMBRE: ";
            cin>>nombre;
            cout<<"PROMEDIO: ";
            cin>>prom;
            //grabar datos
            fprintf(archTemp,"%d\t%s\t%f\n", id, nombre, prom);

        }
    }
    //Cerrar archivos
    fclose(archTxt);
    fclose(archTemp);

    //Eliminar archivo origen y renovar el temporal
    remove("alumnos.txt");
    rename("temporal.txt","alumnos.txt");
    delete [] nombre; 
}