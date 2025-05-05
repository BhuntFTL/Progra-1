#include <iostream>
using namespace std;
#define N 20

// Laberinto de 20x20 (1 es camino, 0 es pared)
int laberinto[N][N] = {
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
int solucion[N][N];

void imprimirLaberinto();
void imprimirSolucion();
int resolverLaberintoUtil(int x, int y);
void resolverLaberinto();

int main() {
    resolverLaberinto();
    return 0;
}



void imprimirLaberinto() {
    cout << "Laberinto Original:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 && j == 0)
                cout << "E "; // Entrada
            else if (i == N - 1 && j == N - 1)
                cout << "S "; // Salida
            else
                cout << (laberinto[i][j] ? "1 " : "0 ");
        }
        cout << endl;
    }
}

void imprimirSolucion() {
    cout << "\nSolución del Laberinto:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 && j == 0)
                cout << "E ";
            else if (i == N - 1 && j == N - 1)
                cout << "S ";
            else
                cout << (solucion[i][j] ? "* " : "0 ");
        }
        cout << endl;
    }
}

int resolverLaberintoUtil(int x, int y) {
    if (x == N - 1 && y == N - 1) {
        solucion[x][y] = 1;
        return 1;
    }
    if (x >= 0 && x < N && y >= 0 && y < N && laberinto[x][y] == 1 && solucion[x][y] == 0) {
        solucion[x][y] = 1;
        if (resolverLaberintoUtil(x + 1, y)) return 1;
        if (resolverLaberintoUtil(x, y + 1)) return 1;
        if (resolverLaberintoUtil(x - 1, y)) return 1;
        if (resolverLaberintoUtil(x, y - 1)) return 1;
        solucion[x][y] = 0;
    }
    return 0;
}

void resolverLaberinto() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            solucion[i][j] = 0;

    imprimirLaberinto();

    if (resolverLaberintoUtil(0, 0))
        imprimirSolucion();
    else
        cout << "No se encontró solución" << endl;
}