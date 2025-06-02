/* Archivos de texto - ABCC */

#include <iostream>
using namespace std;

void altas(FILE*);
void bajas(int, FILE*, FILE*);
void cambios(int, FILE*, FILE*);
void consultas(FILE*);

int main(){
    FILE *archTxt, *archTemp;
    int opc, borrar, idC;

    do{
        cout<<"LISTAS SIMPLES"<<endl;
        cout<<"Altas ............1"<<endl;
        cout<<"Bajas ............2"<<endl;
        cout<<"Cambios ..........3"<<endl;
        cout<<"Consultas ........4"<<endl;
        cout<<"Salir ............5"<<endl;
        cout<<"Tu opcion: ";
        cin>>opc;
        switch(opc){
            case 1: altas(archTxt);
                    break;
            case 2: cout<<"Dame el id para eliminar: ";
                    cin>>borrar;
                    bajas(borrar, archTxt, archTemp);
                    break;
            case 3: cout<<"Dame el id para cambiar sus datos: ";
                    cin>>idC;
                    cambios(idC, archTxt, archTemp);
                    break;
            case 4: consultas(archTxt);
                    break;
        }
    }while(opc!=6);
}

void altas(FILE *archTxt){
    int id;
    float prom;
    char *nombre= new char[25];
    char *turno= new char[15];

    //Abrir archivo
    archTxt= fopen("alumnosABCC.txt","a");

    //Escribir en archivo
    cout<<"ID: ";
    cin>>id;
    cout<<"NOMBRE: ";
    cin>>nombre;
    cout<<"PROMEDIO: ";
    cin>>prom;
    cout<<"TURNO: ";
    cin>>turno;
    //grabar datos
    fprintf(archTxt,"%d\t%s\t%f\t%s\n", id, nombre, prom, turno);

    fclose(archTxt);
}

void bajas(int borrar, FILE *archTxt, FILE *archTemp){
    int id;
    float prom;
    char *nombre= new char[25];
    char *turno= new char[15];

    //Abrir archivo origen para lectura
    archTxt= fopen("alumnosABCC.txt","r");
    archTemp= fopen("temporalABCC.txt","w");

    //mover datos que se van a conservar a temporal
    //leer datos
    while(!feof(archTxt)){
        //Sacar datos del archivo;
        fscanf(archTxt,"%d\t%s\t%f\t%s\n", &id, nombre, &prom, turno);
        //comparar con el que se eliminará, si no es el de borrar se copia en temp
        if(id!=borrar){
            //grabar datos en temporal
            fprintf(archTemp,"%d\t%s\t%f\t%s\n", id, nombre, prom, turno);
        }
    }
    //Cerrar archivos
    fclose(archTxt);
    fclose(archTemp);

    //Eliminar archivo origen y renovar el temporal
    remove("alumnosABCC.txt");
    rename("temporalABCC.txt","alumnosABCC.txt");
    delete [] nombre; 
    delete [] turno; 
}

void cambios(int idC, FILE *archTxt, FILE *archTemp){
    int id;
    float prom;
    char *nombre= new char[25];
    char *turno= new char[15];

    //Abrir archivo origen para lectura
    archTxt= fopen("alumnosABCC.txt","r");
    archTemp= fopen("temporalABCC.txt","w");

    //mover datos que se van a conservar a temporal
    //leer datos
    while(!feof(archTxt)){
        //Sacar datos del archivo;
        fscanf(archTxt,"%d\t%s\t%f\t%s\n", &id, nombre, &prom, turno);
        //comparar con el que se cambiará, si no es el de cambiar se copia en temp
        if(id!=idC){
            //grabar datos en temporal
            fprintf(archTemp,"%d\t%s\t%f\t%s\n", id, nombre, prom, turno);
        }else{
            //registrar nuevos datos sin cambiar id
            cout<<"NOMBRE: ";
            cin>>nombre;
            cout<<"PROMEDIO: ";
            cin>>prom;
            cout<<"TURNO: ";
            cin>>turno;
            //grabar datos
            fprintf(archTemp,"%d\t%s\t%f\t%s\n", id, nombre, prom, turno);

        }
    }
    //Cerrar archivos
    fclose(archTxt);
    fclose(archTemp);

    //Eliminar archivo origen y renovar el temporal
    remove("alumnosABCC.txt");
    rename("temporalABCC.txt","alumnosABCC.txt");
    delete [] nombre; 
    delete [] turno; 
}

void consultas(FILE *archTxt){
    int id, cont=0;
    float prom, promG=0;
    char *nombre= new char[25];
    char *turno= new char[15];

    //Abrir archivo
    archTxt= fopen("alumnosABCC.txt","r");
    //Verificar apertura
    if(!archTxt){ //Si el archivo no se puede abrir
        cout<<"Error de letura!";
        return;
    }
    //Si se puede abrir contunuamos
    cout<<"Contenido del archivo: "<<endl;
    //Mientras no sea fin de archivo
    while(!feof(archTxt)){
        //Sacar datos del archivo;
        fscanf(archTxt,"%d\t%s\t%f\t%s\n", &id, nombre, &prom, turno);
        cout<<id<<"\t"<<nombre<<"\t"<<prom<<"\t"<<turno<<endl;
        cont++;
        promG+=prom;
    }
    
    promG=promG/cont;
    cout<<"El total de alumnos es de: "<<cont<<endl;
    cout<<"El promedio grupal es de: "<<promG<<endl;

    //Cerrar archivo
    fclose(archTxt);
}