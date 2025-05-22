//Arreglos de estructuras

//LIBRERIAS
#include <iostream>

//CONSTANTES
#define MAX 10
using namespace std;

//VARIABLES
static int tope = 0;

//TIPOS DE DATOS
struct Laboratorio{   //datos del fabricante del medicamento
	int cveLab;
	char nomLab[25];
};

struct Fecha{		//fecha de caducidad del medicamento
	int dd,mm,aa;
};

struct Producto{	//medicamentos de la farmacia
	int codigo;
	char nombre[25];
	int stock;
	float precio;
	bool existencia;
	Fecha fechaCad;			//campo de tipo estructura
	Laboratorio fabricante; //campo de tipo estructura
};

//PROTOTIPOS
void menu();
void registro(Producto[]);
void consulta(Producto[]);

//IMPLEMENTACION
int main(){
	menu();
}

void menu(){
	int opc;
	Producto farmacia[MAX];
	do{
		cout << "FARMACIA UAA \n";
		cout << "Registro ......... 1\n";
		cout << "Consultas ........ 2\n";
		cout << "Ventas ........... 3\n";
		cout << "Salir ............ 6\n";
		cin >> opc;
		switch(opc){
			case 1: registro(farmacia); break;
		}
	}while(opc!=6);
}//menu

void registro(Producto farmacia[]){
	cout << "Captura de datos \n";
	//verificar si existe espacio en la farmacia
	if (tope < MAX){
		cout << "Codigo: ";
		cin >> farmacia[tope].codigo;
		cout << "Nombre: ";
		cin >> farmacia[tope].nombre;
		cout << "Stock: ";
		cin >> farmacia[tope].stock;
		cout << "Precio: ";
		cin >> farmacia[tope].precio;
		farmacia[tope].existencia = true;
		cout << "Fecha de caducidad: ";
		cout << "Dia: ";
		cin >> farmacia[tope].fechaCad.dd;
		cout << "Mes: ";
		cin >> farmacia[tope].fechaCad.mm;
		cout << "Año: ";
		cin >> farmacia[tope].fechaCad.aa;
		cout << "Clave del fabricante: ";
		cin >> farmacia[tope].fabricante.cveLab;
		cout << "Nombre del fabricante: ";
		cin >> farmacia[tope].fabricante.nomLab;
		tope++;
	}else{
		cout << "No hay espacio en el almacen \n";
	}
}

void registro(Producto farmacia[]){
	cout << "Medicamentos del almacén \n";
	//verificar si existe espacio en la farmacia
	for(int i=0; i<tope;i++){
		if(farmacia[i].existencia){
			cout << "Codigo: "<<farmacia[i].codigo<<endl;
			cout << "Nombre: "<<farmacia[i].nombre<<endl;
			cout << "Stock: "<<farmacia[i].stock<<endl;
			cout << "Precio: "<<farmacia[i].precio<<endl;
			cout << "Fecha de caducidad: ";
			cout << "Dia: "<<farmacia[i].fechaCad.dd<<endl;
			cout << "Mes: "<<farmacia[i].fechaCad.mm<<endl;
			cout << "Año: "<<farmacia[i].fechaCad.aa<<endl;
			cout << "Clave del fabricante: "<<armacia[i].fabricante.cveLab<<endl;
			cout << "Nombre del fabricante: "<<farmacia[i].fabricante.nomLab<<endl;
		}
	}
}