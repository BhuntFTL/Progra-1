#include <iostream>
#include <string.h>
using namespace std;

void intercambio(char[]);

int main(int argc, const char *argv[]){
    char palabra[100]="";
    for (int i = 1; i < argc; i++){
        strcat(palabra, argv[i]);
    }
    
}

void intercambio(char palabra[]){
    for(int i=0; i<25; i++){
        if(palabra[i]==' '){
            palabra[i]='#';
        }
    }
    cout<<palabra;
}
