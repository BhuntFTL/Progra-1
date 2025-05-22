/*Operaciones con arrelos de caractees
Simular as funciones strlen, strcpy, strcmp, strrev*/

#include <iostream>
#define TAM 25
const int SIZE=10;
using namespace std;

//Funciones propias              //Funciones string.h
int longitud(char[]);            //tam=strLen(cadena);
void copiar(char[],char[]);      //strcpy(cadDes,cadOri);
int comparar(char[],char[]);     //res=strcmp(cadA,cadB);
void reversa(char[]);            //strrev(cadena);

int main(){
	char cadena[TAM], cadA[]={"sistemas"},cadB[SIZE];
	char cadC[SIZE];
	int tam=0;
	
	//obtener la longitud de la cadena
	tam= longitud(cadA);
	cout<<"Longitud de cadA: "<<tam<<endl;
	
	//comparar cadenas
	cout<<"Dame la cadenaB: ";
	cin>>cadB;
	if (comparar(cadA,cadB)==0){
		cout<<"Las cadenas son iguales \n";
	}else{
		cout<<"Las cadenas son distintas \n";
	}	

	//copiar contenido de cadC a cadB
	copiar(cadC,cadB);
	cout<<"CadenaC: "<<cadC<<endl;

	//invertir cadena
	cout<<"Contenido para cadena: ";
	cin>>cadena;
	reversa(cadena);

}

int longitud(char cadA[]){
	int tm=0;
	for(int i=0; cadA[i]=!"\0"; i++){
		tm++;
	}
	return tm;
}

void copiar(char cadC[],char cadB[]){
	int tamB=longitud(cadB);
	for(int i=0; i<tamB; i++){
		cadC[i]=cadB[i];
	}
}

int comparar(char cadA[],char cadB[]){
	int tamA=0, tamB=0, res=0, cont=0;
	//Obtener el tamaño de las cadenas
	tamA=longitud(cadA);
	tamB=longitud(cadB);
	if(tamA==tamB){
		//Comparar posiciones
		for(int i=0; i<tamA; i++){
			if(cadA[i]==cadB[i]){
				cont++;
			}
		}
		//Ver si las cadenas fueron iguales
		if(cont==tamA){
			res=0;
		}else{
			res=1;
		}
	}else{
		//Si son distintas
		res=1;
	}
	return res;
}

void reversa(char cadena[]){
	int cont=0;
	char cadenaInv[TAM];
	int tamCad=longitud(cadena);
	for(int i=tamCad-1; i>0; i--){
		cadenaInv[cont]=cadena[i];
		cont++;
	}
	cout<<"Cadena invertida: "<<cadenaInv;
}
