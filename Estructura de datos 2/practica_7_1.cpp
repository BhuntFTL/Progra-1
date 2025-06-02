#include <iostream>
#include <vector>

using namespace std;

#define MAX 10  // Tamaño máximo de la cola

void insertar(int cola[], int &frente,int &final, int dato) {
    if (final == MAX - 1) {
        cout << "La cola está llena, no se puede insertar más elementos.\n";
        return;
    }
    if (frente == -1) {
        frente = 0;
    }
    final++;
    cola[final] = dato;
    cout << "Elemento " << dato << " insertado en la cola.\n";
}

void quitar(int cola[], int &frente, int &final) {
    if (frente == -1 || frente > final) {
        cout << "La cola está vacía, no hay elementos que quitar.\n";
        return;
    }
    cout << "Elemento " << cola[frente] << " eliminado de la cola.\n";
    frente++;
    if (frente > final) {  // Si la cola se vacía completamente, restablecer índices
        frente = final = -1;
    }
}

void mostrar(int cola[], int &frente, int &final) {
    if (frente == -1 || frente > final) {
        cout << "La cola está vacía.\n";
        return;
    }
    cout << "Contenido de la cola: ";
    for (int i = frente; i <= final; i++) {
        cout << cola[i] << " ";
    }
    cout << "\n";
}

int main() {
    int cola[MAX];
    int frente = -1, final = -1;
    insertar(cola,frente,final,10);
    insertar(cola,frente,final,20);
    insertar(cola,frente,final,30);
    mostrar(cola,frente,final);

    quitar(cola,frente,final);
    mostrar(cola,frente,final);

    quitar(cola,frente,final);
    mostrar(cola,frente,final);

    return 0;
}