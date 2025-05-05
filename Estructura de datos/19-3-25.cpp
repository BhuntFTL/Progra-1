// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
//Hacemos el prototipo de la funcion
void verificar(int[], int[]);
void mostrar(int[]);
int main() {
    //Declaramos los vectores a utilizar
    int v1[7]={3,5,9,11,12,8,7};
    int v2[3]={9,11,12};
    int v3[3]={3,8,9};
    //Mandamos a llamar la función para ambos casos
    verificar(v1,v2);
    verificar(v1,v3);
}
//Esta funcion verificará si son subconjuntos
void verificar(int v1[], int v2[]){
    //Declaramos un vector donde se guardaran las posiciones
    int vector[3];
    //Variables que nos indicaran si es continuo y si existen en el vector original
    bool continuo=false;
    bool existe=false;
    //Mandamos a llamar la funcion que muestra los vectores
    mostrar(v1);
    mostrar(v2);
    //Verifica posicion por posicion si son iguales y lo guarda eb el vector de las posiciones
    for(int i=0; i<3; i++){
        for(int j=0; j<7; j++){
            if(v1[j]==v2[i]){
                vector[i]=j;
                existe=true;
            }
        }
    }
    //Imprime que es subconjunto si existio
    if(existe){
        cout<<"\n"<<"Es un subconjunto del vector"<<endl;
    }
    //Verificamos si las posiciones guardadas son continuas
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(vector[i]==vector[j]+1){
                continuo=true;
            }
        }
    }
    //Si es continuo imprime el vector donde se guardaron las posiciones
    if(continuo){
        cout<<"Las posiciones son: "<<endl;
        for(int i=0; i<3; i++){
            cout<<vector[i]<<" ";
        }
    }
}
void mostrar(int vec[]){
    cout<<"\n"<<"Vector: "<<endl;
    for(int i=0; i<7; i++){
        cout<<vec[i]<<" ";
    }
}
