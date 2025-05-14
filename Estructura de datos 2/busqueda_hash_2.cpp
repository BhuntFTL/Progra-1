#include <iostream>
using namespace std;

int busquedaHash(int vector[], int buscar, int n);
void insertarHash(int tablaHash[], int valor, int n, int& posicion);

int main() {
    int n, buscar, posicion;
    
    cout << "Número de datos: ";
    cin >> n;
    
    int* vector = new int[n];
    
    for(int i = 0; i < n; i++) {
        cout << "Dato " << i << ": ";
        cin >> vector[i];
    }
    
    cout << "¿Qué valor desea buscar? ";
    cin >> buscar;
    
    posicion = busquedaHash(vector, buscar, n);
    
    if(posicion != -1) {
        if(posicion >= n) {
            cout << "El valor " << buscar << " se encontró en el área de colisiones (posición " << posicion << ")" << endl;
        } else {
            cout << "El valor " << buscar << " se encontró en la posición primaria " << posicion << endl;
        }
    } else {
        cout << "El valor " << buscar << " no se encontró en la tabla hash." << endl;
    }
    
    delete[] vector;
    return 0;
}

void insertarHash(int tablaHash[], int valor, int n, int& posicion) {
    int aux = valor % n; // Posición en la primera mitad
    
    if(tablaHash[aux] == 0) {
        // Caso ideal: posición libre
        tablaHash[aux] = valor;
        posicion = aux;
    } else {
        // Colisión: almacenar en segunda mitad
        for(int i = n; i < 2*n; i++) {
            if(tablaHash[i] == 0) {
                tablaHash[i] = valor;
                posicion = i;
                return;
            }
        }
        // Si llegamos aquí, la tabla de colisiones está llena
        posicion = -1;
    }
}

int busquedaHash(int vector[], int buscar, int n) {
    int* tablaHash = new int[2*n](); // Tabla de tamaño 2n inicializada a 0
    int posicion = -1;
    
    // Primero insertamos todos los valores
    for(int i = 0; i < n; i++) {
        insertarHash(tablaHash, vector[i], n, posicion);
    }
    
    // Ahora buscamos el valor específico
    posicion = -1; // Resetear para la búsqueda
    
    // Buscar en la primera mitad (posición primaria)
    int aux = buscar % n;
    if(tablaHash[aux] == buscar) {
        posicion = aux;
    } else {
        // Buscar en el área de colisiones
        for(int i = n; i < 2*n; i++) {
            if(tablaHash[i] == buscar) {
                posicion = i;
                break;
            }
        }
    }
    
    delete[] tablaHash;
    return posicion;
}