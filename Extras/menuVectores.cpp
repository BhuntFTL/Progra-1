//_Menu de Vectores
//_Antonio Durón Mendoza y Tania Jaquelin López Acevedo
//_19/02/25
//_Est. de datos
#include <iostream>
using namespace std;
#define N 5

void mostrarMenu();
void llenar(int[]);
void llenar2(int[]);
void mostrar(int[]);
void mostrar2(int[]);
void mayorMenor(int[]);
void conteo(int[]);
void suma(int[]);
void promedio(int[]);
void cruz(int[],int[]);
bool verificar(string);

int main(){
    mostrarMenu();
}

void mostrarMenu(){
    int vector[N],vec1[3],vec2[3];
    int opc=0;
    string valor;
    do{
        cout<<"\nOpciones: "<<endl;
        cout<<"1.- Mayor y menor de un vector"<<endl;
        cout<<"2.- Conteo de un numero dado"<<endl;
        cout<<"3.- Suma de elementos de un vector"<<endl;
        cout<<"4.- Promedio de los elementos de un vector"<<endl;
        cout<<"5.- Producto cruz de 2 vectores de 3 componentes"<<endl;
        cout<<"6.- Salir"<<endl;
        cin>>valor;
        if (verificar(valor)) {
            opc = stoi(valor);
        } else {
            cout << "Invalido. Ingrese otra opcion: ";
        }
        switch(opc){
            case 1: mayorMenor(vector); break;
            case 2: conteo(vector); break;
            case 3: suma(vector); break;
            case 4: promedio(vector); break;
            case 5: cruz(vec1,vec2); break;
        }
    }while(opc!=6);
}

bool verificar(string valor) {
    for (char c : valor) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
void llenar(int vector[]){
    string valor;
    for (int i = 0; i < N; i++){
        cout << "Elemento " << i + 1 << ": ";
        while (true) {
            cin >> valor;
            if (verificar(valor)) {
                vector[i] = stoi(valor);
                break;
            } else {
                cout << "Invalido. Ingrese un numero entero: ";
            }
        }
    }
}
void llenar2(int vector[]){
    string valor;
    for (int i = 0; i < 3; i++){
        cout << "Elemento " << i + 1 << ": ";
        while (true) {
            cin >> valor;
            if (verificar(valor)) {
                vector[i] = stoi(valor);
                break;
            } else {
                cout << "Invalido. Ingrese un numero entero: ";
            }
        }
    }
}
void mostrar(int vector[]){
    for (int i=0; i<N; i++){
        cout<<"["<<vector[i]<<"] ";
    }
    cout<<"\n";
}
void mostrar2(int vector[]){
    for (int i=0; i<3; i++){
        cout<<"["<<vector[i]<<"] ";
    }
    cout<<"\n";
}
void mayorMenor(int vector[]){
    int menor=9999999, mayor=0;
    llenar(vector);
    mostrar(vector);
    for (int i=0; i<N; i++){
        if(vector[i]>mayor){
            mayor=vector[i];
        }
        if(vector[i]<menor){
            menor=vector[i];
        }
    }
    cout<<"\nMayor: "<<mayor<<endl;
    cout<<"Menor: "<<menor<<endl;
}
void conteo(int vector[]){
    int num=0, veces=0;
    llenar(vector);
    mostrar(vector);
    cout<<"Contar: ";
    cin>>num;
    for(int i=0; i<N;i++){
        if(vector[i]==num){
            veces++;
        }
    }
    cout<<"Se encontro "<<veces<<" veces"<<endl;
}
void suma(int vector[]){
    int suma=0;
    llenar(vector);
    mostrar(vector);
    for (int i=0; i<N; i++){
        suma+=vector[i];
    }
    cout<<"La suma es: "<<suma<<endl;
}
void promedio(int vector[]){
    int suma=0;
    float promedio=0;
    llenar(vector);
    mostrar(vector);
    for (int i=0; i<N; i++){
        suma+=vector[i];
    }
    promedio=suma/N;
    cout<<"El promedio es: "<<promedio<<endl;
}
void cruz(int vec1[], int vec2[]){
    int vectorf[3];
    cout<<"Vector 1: "<<endl;
    llenar2(vec1);
    mostrar2(vec1);
    cout<<"Vector 2: "<<endl;
    llenar2(vec2);
    mostrar2(vec2);
    vectorf[0]=vec1[1]*vec2[2]-vec2[1]*vec1[2];
    vectorf[1]=(vec1[0]*vec2[2]-vec2[0]*vec1[2])*-1;
    vectorf[2]=vec1[0]*vec2[1]-vec1[1]*vec2[0];
    cout<<"El resultado es: "<<endl;
    mostrar2(vectorf);
}//_Menu de Vectores
//_Antonio Durón Mendoza y Tania Jaquelin López Acevedo
//_19/02/25
//_Est. de datos
#include <iostream>
using namespace std;
#define N 5

void mostrarMenu();
void llenar(int[]);
void llenar2(int[]);
void mostrar(int[]);
void mostrar2(int[]);
void mayorMenor(int[]);
void conteo(int[]);
void suma(int[]);
void promedio(int[]);
void cruz(int[],int[]);
bool verificar(string);

int main(){
    mostrarMenu();
}

void mostrarMenu(){
    int vector[N],vec1[3],vec2[3];
    int opc=0;
    string valor;
    do{
        cout<<"\nOpciones: "<<endl;
        cout<<"1.- Mayor y menor de un vector"<<endl;
        cout<<"2.- Conteo de un numero dado"<<endl;
        cout<<"3.- Suma de elementos de un vector"<<endl;
        cout<<"4.- Promedio de los elementos de un vector"<<endl;
        cout<<"5.- Producto cruz de 2 vectores de 3 componentes"<<endl;
        cout<<"6.- Salir"<<endl;
        cin>>valor;
        if (verificar(valor)) {
            opc = stoi(valor);
        } else {
            cout << "Invalido. Ingrese otra opcion: ";
        }
        switch(opc){
            case 1: mayorMenor(vector); break;
            case 2: conteo(vector); break;
            case 3: suma(vector); break;
            case 4: promedio(vector); break;
            case 5: cruz(vec1,vec2); break;
        }
    }while(opc!=6);
}

bool verificar(string valor) {
    for (char c : valor) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
void llenar(int vector[]){
    string valor;
    for (int i = 0; i < N; i++){
        cout << "Elemento " << i + 1 << ": ";
        while (true) {
            cin >> valor;
            if (verificar(valor)) {
                vector[i] = stoi(valor);
                break;
            } else {
                cout << "Invalido. Ingrese un numero entero: ";
            }
        }
    }
}
void llenar2(int vector[]){
    string valor;
    for (int i = 0; i < 3; i++){
        cout << "Elemento " << i + 1 << ": ";
        while (true) {
            cin >> valor;
            if (verificar(valor)) {
                vector[i] = stoi(valor);
                break;
            } else {
                cout << "Invalido. Ingrese un numero entero: ";
            }
        }
    }
}
void mostrar(int vector[]){
    for (int i=0; i<N; i++){
        cout<<"["<<vector[i]<<"] ";
    }
    cout<<"\n";
}
void mostrar2(int vector[]){
    for (int i=0; i<3; i++){
        cout<<"["<<vector[i]<<"] ";
    }
    cout<<"\n";
}
void mayorMenor(int vector[]){
    int menor=9999999, mayor=0;
    llenar(vector);
    mostrar(vector);
    for (int i=0; i<N; i++){
        if(vector[i]>mayor){
            mayor=vector[i];
        }
        if(vector[i]<menor){
            menor=vector[i];
        }
    }
    cout<<"\nMayor: "<<mayor<<endl;
    cout<<"Menor: "<<menor<<endl;
}
void conteo(int vector[]){
    int num=0, veces=0;
    llenar(vector);
    mostrar(vector);
    cout<<"Contar: ";
    cin>>num;
    for(int i=0; i<N;i++){
        if(vector[i]==num){
            veces++;
        }
    }
    cout<<"Se encontro "<<veces<<" veces"<<endl;
}
void suma(int vector[]){
    int suma=0;
    llenar(vector);
    mostrar(vector);
    for (int i=0; i<N; i++){
        suma+=vector[i];
    }
    cout<<"La suma es: "<<suma<<endl;
}
void promedio(int vector[]){
    int suma=0;
    float promedio=0;
    llenar(vector);
    mostrar(vector);
    for (int i=0; i<N; i++){
        suma+=vector[i];
    }
    promedio=suma/N;
    cout<<"El promedio es: "<<promedio<<endl;
}
void cruz(int vec1[], int vec2[]){
    int vectorf[3];
    cout<<"Vector 1: "<<endl;
    llenar2(vec1);
    mostrar2(vec1);
    cout<<"Vector 2: "<<endl;
    llenar2(vec2);
    mostrar2(vec2);
    vectorf[0]=vec1[1]*vec2[2]-vec2[1]*vec1[2];
    vectorf[1]=(vec1[0]*vec2[2]-vec2[0]*vec1[2])*-1;
    vectorf[2]=vec1[0]*vec2[1]-vec1[1]*vec2[0];
    cout<<"El resultado es: "<<endl;
    mostrar2(vectorf);
}