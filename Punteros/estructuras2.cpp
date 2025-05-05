//Ejercicio con estricturas y punteros a estructuras
#include <iostream>
#define MAX 100
static int tope=0;
using namespace std;

struct Fecha{
    int dia;
    int mes;
    int anio;
};
struct Hospital{
    char nombre[25];
    float peso;
    int edad;
    char tipoEnf;
    Fecha fechaNac;

};

void menu();
void llenar(Hospital*);
int enfermedad(Hospital*);
void consultar(Hospital*, int);

int main(){
    menu();
}

void menu(){
    int opc;
    int cantidad, num;
    Hospital enfermos[MAX];
    do{
        cout<<"BIENVENIDO AL SISTEMA DEL HOSPITAL"<<endl;
        cout<<"1.- Registrar paciente"<<endl;
        cout<<"2.- Consultar paciente"<<endl;
        cout<<"3.- Pacientes con enfermedad 'c'"<<endl;
        cout<<"4.- Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opc;
        switch(opc){
            case 1: llenar(enfermos); break;
            case 2: cout<<"Numero de enfermo a buscar: ";
                    cin>>num;
                    consultar(enfermos,num);
                    break;
            case 3: cantidad=enfermedad(enfermos);
                    cout<<"La cantidad de enfermos con la enfermedad C, son: "<<cantidad<<endl;
        }
    }while(opc!=4);
   
    
    
    
}

void llenar(Hospital *enfermos){
    if(tope<MAX){
        cout<<"DATOS DEL PACIENTE"<<endl;
        cout<<"Nombre: ";
        cin>>(*(enfermos+tope)).nombre;
        cout<<"Peso: ";
        cin>>(*(enfermos+tope)).peso;
        cout<<"Edad: ";
        cin>>(*(enfermos+tope)).edad;
        cout<<"Tipo de Enfermedad: ";
        cin>>(*(enfermos+tope)).tipoEnf;
        cout<<"FECHA DE NACIMIENTO"<<endl;
        cout<<"Día: ";
        cin>>(*(enfermos+tope)).fechaNac.dia;
        cout<<"Mes: ";
        cin>>(*(enfermos+tope)).fechaNac.mes;
        cout<<"Año: ";
        cin>>(*(enfermos+tope)).fechaNac.anio;
        tope++;
    }else{
        cout<<"Ya no hay espacio";
    }
}

int enfermedad(Hospital *enfermos){
    int contador=0;
    for(int i=0; i<tope; i++){
        if((*(enfermos+i)).tipoEnf=='c'){
            contador++;
        }
    }
    return contador;
}

void consultar(Hospital *enfermos, int num){
    if(num>tope){
        cout<<"Lo lamento, no se encontro ese numero de paciente"<<endl;
    }else{
        for(int i=0; i<tope; i++){
            if(i==num){
                cout<<"PACIENTE ENCONTRADO"<<endl;
                cout<<"DATOS DEL PACIENTE"<<endl;
                cout<<"Nombre: "<<(*(enfermos+i)).nombre<<endl;
                cout<<"Peso: "<<(*(enfermos+i)).peso<<endl;
                cout<<"Edad: "<<(*(enfermos+i)).edad<<endl;
                cout<<"Tipo de Enfermedad: "<<(*(enfermos+tope)).tipoEnf<<endl;
                cout<<"FECHA DE NACIMIENTO"<<endl;
                cout<<"Día: "<<(*(enfermos+i)).fechaNac.dia<<endl;
                cout<<"Mes: "<<(*(enfermos+i)).fechaNac.mes<<endl;
                cout<<"Año: "<<(*(enfermos+i)).fechaNac.anio<<endl;
            }
        }
    }
    

}

