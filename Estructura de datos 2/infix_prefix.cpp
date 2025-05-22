#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// Función para definir la prioridad de los operadores
int prioridad(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infijoAPrefijo(const string &infijo) {
    string invertida = infijo;
    reverse(invertida.begin(), invertida.end());

    string prefijo;
    char pila[100];
    int indice = -1;
    for (char c : invertida) {
        if (isalnum(c)) {
            prefijo += c;
        } else if (c == ')') {
            pila[++indice] = c;
        } else if (c == '(') {
            while (indice >= 0 && pila[indice] != ')') {
                prefijo += pila[indice--];
            }
            indice--;
        } else {
            while (indice >= 0 && prioridad(pila[indice]) > prioridad(c)) {
                prefijo += pila[indice--];
            }
            pila[++indice] = c;
        }
    }
    while (indice >= 0) {
        prefijo += pila[indice--];
    }
    reverse(prefijo.begin(), prefijo.end());
    return prefijo;
}

int main() {
    string infijo;
    cout << "Ingrese una expresión en notación infija: ";
    cin >> infijo;

    string prefijo = infijoAPrefijo(infijo);
    cout << "Expresión en notación prefija: " << prefijo << endl;

    return 0;
}