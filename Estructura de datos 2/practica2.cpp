#include <iostream>
using namespace std;

#define N 2

void permutar(char letras[], int ini, int fin);

int main(int argc, const char * argv[]){
    char letras[]={'a','b','c','d','e'};

cout<<"programa para obtener las permutaciones posibles\n";
    cout<<"Las permutaciones con "<<N<<" son: "<<endl;
    permutar(letras, 0, N);

    return 0;
}
//Función recursiva para generar permutaciones
void permutar(char letras[], int ini, int fin){
    char aux;
    if(ini==fin){
        //Caso base: Imprimir la permutación actual
        for(int i=0; i<fin; ++i){
            cout<<letras[i]<<" ";
        }
        cout<<endl;
    }else{
        //Caso recursivo
        for(int i=ini; i<fin; i++){
            //Intercambiar los elementos
            aux=letras[ini];
            letras[ini]=letras[i];
            letras[i]=aux;
            //Llamar recursivamente para el subconjunto restante
            permutar(letras, ini+1, fin);
            //Volver a intercambiar para restaurar el orden original
            aux=letras[ini];
            letras[ini]=letras[i];
            letras[i]=aux;
        }
    }
}