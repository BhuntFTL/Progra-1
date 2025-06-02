//Lectura-Escritura en archivos de texto -fputc,fgetc

#include <iostream>
#include <ctype.h>

int main(){
	FILE *planeta, *auxiliar;  
	char letra; /*aqui se almacena la letra que se 
				extrae del archivo */
	//abrir planeta para lectura 
	planeta = fopen("planet.txt","r");
	
	//abrir auxiliar para escritura
	auxiliar = fopen("auxiliar.txt","w");
	
	/*recorrer el archivo planeta, extraer una letra
	evaluar la letra y mandar a pantalla o al auxiliar*/
	letra = fgetc(planeta);
	while(!feof(planeta)){
		letra = fgetc(planeta);  //extrae letra por letra
		if (ispunct(letra)){
			fputc(letra,auxiliar); //grabar el simbolo en auxiliar
			putchar('#'); //pone en pantalla
		}else{
			putchar(letra);
		}
	}
	fclose(planeta);
	fclose(auxiliar);	
}

