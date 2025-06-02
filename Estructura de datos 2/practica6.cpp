#include <iostream>
#include <cmath>
using namespace std;
#define TAM 20

// Función para definir la prioridad de los operadores
int prioridad(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Función para convertir una expresión infija a postfija sin usar pila
string infijoAPostfijo(const string &infijo) {
    string postfijo;
    char pila[100]; 
    int indice = -1;
    for (char c : infijo) {
        if (isalnum(c)) {
            postfijo += c; // Si es operando, agregarlo a la salida
        } else if (c == '(') {
            pila[++indice] = c;
        } else if (c == ')') {
            while (indice >= 0 && pila[indice] != '(') {
                postfijo += pila[indice--];
            }
            indice--; // Eliminar el paréntesis izquierdo
        } else { // Si es operador
            while (indice >= 0 && prioridad(pila[indice]) >= prioridad(c)) {
                postfijo += pila[indice--];
            }
            pila[++indice] = c;
        }
    }
    // Agregar los operadores restantes
    while (indice >= 0) {
        postfijo += pila[indice--];
    }
    return postfijo;
}

void evaluar(string expresion){
    int pila[TAM];
    int i=0, a, b, z; // Índice de la pila (inicialmente vacía)
    for(char valor : expresion){
        if(isdigit(valor)){
            pila[i++]=valor-'0'; // Convertir char a int y apilar
        }else if(valor==' '){
            continue; // Ignorar espacios
        }else{
            // Desapilar los dos últimos elementos
            b=pila[--i]; // Primero el operando derecho (b)
            a=pila[--i]; // Luego el operando izquierdo (a)
            
            // Realizar la operación
            switch(valor){
                case '+': pila[i++]=a+b; break;
                case '-': pila[i++]=a-b; break;
                case '*': pila[i++]=a*b; break;
                case '/': pila[i++]=a/b; break;
                case '^': pila[i++]=pow(a, b); break;
            }
        }
    }
    cout << "El resultado de la expresion es: " << pila[0] << endl;
}

int main(){
    string expresion; 
    cout<<"Expresion: ";
    cin>>expresion; // Usar getline para leer espacios
    expresion=infijoAPostfijo(expresion);
    evaluar(expresion);
}