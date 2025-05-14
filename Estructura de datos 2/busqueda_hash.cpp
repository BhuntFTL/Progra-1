#include <iostream>
using namespace std;

int busquedaHash(int vector[], int buscar, int n);
int comprobar(int tablaHash[], int valor, int aux, int buscar, int n, int &posicion);

int main() {
    int n, buscar, posicion;
    
    cout<<"Número de datos: ";
    cin>>n;
    
    int *vector= new int[n];
    
    for(int i=0; i<n; i++){
        cout<<"Dato "<<i<<": ";
        cin>>vector[i];
    }
    cout<<"¿Qué valor desea buscar? ";
    cin>>buscar;

    posicion=busquedaHash(vector, buscar, n);
    if(posicion != -1){
        cout<<"El valor "<<buscar<<" se encuentra en la posición "<<posicion<<endl;
    }else{
        cout<<"-1 el valor "<<buscar<<" no se encontró en la tabla hash."<<endl;
    }
    
    delete[] vector;
    return 0;
}

int comprobar(int tablaHash[], int valor, int aux, int buscar, int n, int &posicion) {
    if(tablaHash[aux] == 0){
        tablaHash[aux] = valor;
        if(valor == buscar){
            posicion = aux;
        }
    }else{
        aux = (aux + 1) % n;
        comprobar(tablaHash, valor, aux, buscar, n, posicion);
    }
    return posicion;
}

int busquedaHash(int vector[], int buscar, int n){
    int* tablaHash = new int[n](); // Inicializa a ceros
    int posicion = -1;
    
    for(int i = 0; i < n; i++){
        int aux = vector[i] % n;
        comprobar(tablaHash, vector[i], aux, buscar, n, posicion);
    }
    
    delete[] tablaHash;
    return posicion;
}