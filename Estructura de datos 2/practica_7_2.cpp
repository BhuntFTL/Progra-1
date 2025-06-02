#include <iostream>

using namespace std;

#define MAX 10  // Tamaño máximo de la cola circular

void insertar(int cola[], int &frente, int &final, int &contador, int dato) {
    if (contador == MAX) {
        cout << "La cola está llena, no se puede insertar más elementos.\n";
        return;
    }
    final = (final + 1) % MAX;
    cola[final] = dato;
    if (frente == -1) {
        frente = 0;
    }
    contador++;
    cout << "Elemento " << dato << " insertado en la cola.\n";
}

void quitar(int cola[], int &frente, int &final, int &contador) {
    if (contador == 0) {
        cout << "La cola está vacía, no hay elementos que quitar.\n";
        return;
    }
    cout << "Elemento " << cola[frente] << " eliminado de la cola.\n";
    frente = (frente + 1) % MAX;
    contador--;
    if (contador == 0) {  // Si la cola se vacía completamente, restablecer índices
        frente = final = -1;
    }
}

void mostrar(int cola[], int &frente, int &final, int &contador) {
    if (contador == 0) {
        cout << "La cola está vacía.\n";
        return;
    }
    cout << "Contenido de la cola: ";
    for (int i = 0, index = frente; i < contador; i++) {
        cout << cola[index] << " ";
        index = (index + 1) % MAX;
    }
    cout << "\n";
}

int main() {
    int cola[MAX];
    int frente = -1, final = -1, contador = 0;

    insertar(cola, frente, final, contador, 10);
    insertar(cola, frente, final, contador, 20);
    insertar(cola, frente, final, contador, 30);
    mostrar(cola, frente, final, contador);
    cout<<"Frente: "<<frente<<"\t"<<"Final: "<<final<<endl;

    quitar(cola, frente, final, contador);
    mostrar(cola, frente, final, contador);
    cout<<"Frente: "<<frente<<"\t"<<"Final: "<<final<<endl;


    quitar(cola, frente, final, contador);
    mostrar(cola, frente, final, contador);
    cout<<"Frente: "<<frente<<"\t"<<"Final: "<<final<<endl;


    return 0;
}