#include <iostream>
#include <cstring>

using namespace std;

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

int main() {
    string infijo;
    cout << "Ingrese una expresión en notación infija: ";
    cin >> infijo;

    string postfijo = infijoAPostfijo(infijo);
    cout << "Expresión en notación postfija: " << postfijo << endl;

    return 0;
}