/* Archivos de texto - ABCC */

#include <iostream>
using namespace std;

struct Alumnos{
    int id;
    char nombre[25];
    float prom;
    char turno[10];
    bool estado;
};

void altas(FILE*);
void bajasl(int, FILE*);
void bajasf(int, FILE*, FILE*);
void cambios(int, FILE*);
void consultas(FILE*);

int main(){
    FILE *archBin, *archTemp;
    int opc, borrar, idC;

    do{
        cout<<"ARCHIVOS BINARIOS"<<endl;
        cout<<"Altas ............1"<<endl;
        cout<<"Bajas lógicas ....2"<<endl;
        cout<<"Bajas físicas ....3"<<endl;
        cout<<"Cambios ..........4"<<endl;
        cout<<"Consultas ........5"<<endl;
        cout<<"Salir ............6"<<endl;
        cout<<"Tu opcion: ";
        cin>>opc;
        switch(opc){
            case 1: altas(archBin);
                    break;
            case 2: cout<<"Dame el id para eliminar logicamente: ";
                    cin>>borrar;
                    bajasl(borrar, archBin);
                    break;
            case 3: bajasf(archBin, archTemp);
                    break;
            case 4: cout<<"Dame el id para cambiar sus datos: ";
                    cin>>idC;
                    cambios(idC, archBin);
                    break;
            case 5: consultas(archBin);
                    break;
        }
    }while(opc!=6);
}

void altas(FILE *archBin){
    Alumnos alumno;

    //Abrir archivo
    archBin=fopen("alumnos.bin","ab");

    //Escribir en archivo
    cout<<"ID: ";
    cin>>alumno.id;
    cout<<"NOMBRE: ";
    cin>>alumno.nombre;
    cout<<"PROMEDIO: ";
    cin>>alumno.prom;
    cout<<"TURNO: ";
    cin>>alumno.turno;
    alumno.estado=true;
    //grabar datos
    fwrite(&alumno, sizeof(Alumnos), 1, archBin);

    fclose(archBin);
}

void bajasl(int borrar, FILE *archBin){
    Alumnos alumno;
    //Abrir archivo origen para lectura
    archBin= fopen("alumnos.bin","rb+");

    while (fread(&alumno, sizeof(Alumnos), 1, archBin)){
        if (alumno.id == borrar){
            alumno.estado=false;
            //Nos posicionamos en el lugar a modificar
            fseek(archBin,-sizeof(Alumnos),SEEK_CUR);//IMPORT ANTE EL MENOS (SE coloca antes de la estructura y no despues de la estructura, si no lo repite)
            //Grabamos los datos (en el apuntador antes colocado)
            fwrite(&alumno,sizeof(Alumnos),1,archBin);
            break;
        }
    }
    // Cerrar el archivo
    fclose(archBin);
}

void bajasf(FILE *archBin, FILE *archTemp){
    Alumnos alumno;
    //Abrir archivo origen para lectura
    archBin= fopen("alumnos.bin","rb+");
    archTemp= fopen("temp.bin","ab");

    while (fread(&alumno, sizeof(Alumnos), 1, archBin)){
        if(alumno.estado){
            fwrite(&alumno, sizeof(Alumnos), 1, archTemp);
        }
    }
    remove("alumnos.bin");
    rename("temp.bin","alumnos.bin");
    // Cerrar el archivo
    fclose(archBin);
    fclose(archTemp);
}

void cambios(int cambiar, FILE *archBin){
    Alumnos alumno;
    int opc;
    //Abrir archivo origen para lectura
    archBin= fopen("alumnos.bin","rb+");
    cout<<"Modificar"<<endl;
    cout<<"1. Nombre"<<endl;
    cout<<"2. Promedio"<<endl;
    cout<<"3. Turno"<<endl;
    cout<<"Opcion: ";
    cin>>opc;
    while (fread(&alumno, sizeof(Alumnos), 1, archBin)){
        if(cambiar==alumno.id){
            switch (opc){
                case 1: cout<<"NOMBRE: ";
                        cin>>alumno.nombre;
                        break;
                case 2: cout<<"PROMEDIO: ";
                        cin>>alumno.prom;
                        break;
                case 3: cout<<"TURNO: ";
                        cin>>alumno.turno;
                        break;
            }
            fseek(archBin,-sizeof(Alumnos),SEEK_CUR); //IMPORTANTE EL MENOS (SE coloca antes de la estructura y no despues de la estructura, si no lo repite)
            //Grabamos los datos (en el apuntador antes colocado)
            fwrite(&alumno,sizeof(Alumnos),1,archBin);
            break;
        }
    }
    // Cerrar el archivo
    fclose(archBin);
}

void consultas(FILE *archBin){
    Alumnos alumno;
    float promG=0;
    int cont=0, cont2=0;
    archBin=fopen("alumnos.bin","rb");
    while(fread(&alumno, sizeof(Alumnos), 1, archBin)){
        if(alumno.estado){
            cout<<"ID: "<<alumno.id<<endl;
            cout<<"Nombre: "<<alumno.nombre<<endl;
            cout<<"Promedio: "<<alumno.prom<<endl;
            cout<<"Turno: "<<alumno.turno<<endl<<endl;
            cont++;
            promG+=alumno.prom;
            if(alumno.prom<=7){
                cont2++;
            }
        }
    }
    promG=promG/cont;
    cout<<"El total de alumnos es de: "<<cont<<endl;
    cout<<"El promedio grupal es de: "<<promG<<endl;
    cout<<"Alumnos con 7 o menos: "<<cont2<<endl;

    fclose(archBin);
}