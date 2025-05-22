//Archivos de texto - Grabar datos
#include <iostream>
using namespace std;

int main(){
    //Declarar archivo
    FILE *archTxt; //Variable par manejar el archivo
    int id;
    float prom;
    char *nombre= new char[25], resp;
    //nombre=(char*)malloc(25*sizeof(char));

    //Abrir archivo
    archTxt= fopen("alumnos.txt","a");

    //Escribir en archivo
    do{
        cout<<"ID: ";
        cin>>id;
        cout<<"NOMBRE: ";
        cin>>nombre;
        cout<<"PROMEDIO: ";
        cin>>prom;
        //grabar datos
        fprintf(archTxt,"%d\t%s\t%f\n", id, nombre, prom);
        cout<<"COntinuar s/n: ";
        cin>>resp;
    }while(resp!='n');

    //Cerrar archivo
    fclose(archTxt);


}