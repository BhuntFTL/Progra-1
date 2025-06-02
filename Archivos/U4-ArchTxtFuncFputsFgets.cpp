//Lectura-Escritura en archivos de texto -fputc,fgetc

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(){
	FILE *planeta, *temporal;  
	int tamCad=0;
	/*aqui se almacena la cadena que se extrae del archivo */
	char *cadena=new char[256], *cadTam=new char[100];

	//abrir planeta para lectura 
	planeta = fopen("planet.txt","r");
	
	//abrir temporal para escritura
	temporal = fopen("temporal.txt","w");
	
	//recorrer archivo para extraer cadenas
	while(!feof(planeta)){
		tamCad=0;
		fgets(cadena,256,planeta);
		tamCad = strlen(cadena);
		itoa(tamCad,cadTam,10);
		fputs(cadTam,temporal);
		fputs("\n",temporal);
	}
	cout << "Cadenas leidas y medidas \n";
	delete [] cadTam;
	delete [] cadena;
	fclose(planeta);
	fclose(temporal);
}
