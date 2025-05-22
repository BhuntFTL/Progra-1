#include <iostream>
using namespace std;

#define MAX 100
#define tipoDato int

tipoDato listaPila[MAX];
int cima;

// Declaración de funciones
void crearPila(void);
void insertar(tipoDato elemento);
tipoDato quitar(void);
tipoDato getCima(void);

int pilaVacia(void);
int pilaLlena(void);
void limpiarPila(void);

// Función principal
int main(int argc, const char * argv[]) {
    int x;
    crearPila();
    puts("\nLa plia crece con numeros enteros, termina con 0");
    do{
        scanf("%d", &x);
        if(!pilaLlena()) {
            insertar(x);
        }else{
            puts("\n la pila se ha llenado.\n");
            x=0;
        }
    }while(x!=0);
    puts("Une elemento de la pila son: ");
    while(!pilaVacia()) {
        printf("En la cima: %d \t", getCima());
        x=quitar();
        printf("Elemento %d fuerz \n", x);
    }

    printf("\n");
    return 0;
}

// Operaciones sobre la pila
void crearPila(void){
    cima = -1;
}

void insertar(tipoDato elemento){
    if(pilaLlena()){
        puts("Desbordamiento de pila");
    } else {
        cima++;
        listaPila[cima] = elemento;
    }
}

tipoDato quitar(void){
    tipoDato temp;
    if(pilaVacia()){
        puts("Se intenta sacar un elemento en pila vacia");
        return -1;
    } else {
        temp = listaPila[cima];
        cima--;
        return temp;
    }
}

tipoDato getCima(void){
    if(pilaVacia()){
        puts("Error de ejecución, pila vacia");
        return -1;
    }
    return listaPila[cima];
}

// Verificar estado de la pila
int pilaVacia(void){
    return cima == -1;
}

int pilaLlena(void){
    return cima == MAX - 1;
}

void limpiarPila(void){
    cima = -1;
}

