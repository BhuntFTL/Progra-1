#include <iostream>
#define N 10
using namespace std;

int main(){
    int vector[N];

    /*Capturar valores*/
    for (int i = 0; i < N; i++){
        cout<<"Dame un valor: ";
        cin>>vector[i];
    }
    for (int i = 0; i < N; i++){
        cout<<vector[i]<<" "<<endl;
    }

    /*Promedio de valores*/
    int j=0, suma=0, prom;
    while(j<N){
        suma+=vector[j]; /*Se suman los valores*/
        j++;
    }
    prom=suma/N;
    cout<<"La suma es: "<<suma<<endl;
    cout<<"El promedio es: "<<prom<<endl;

    /*Menor y mayor*/
    int k=0, menor=9999, mayor=0;
    do{
        if(vector[k]<=menor){
            menor=vector[k];
        }
        if(vector[k]>=mayor){
            mayor=vector[k];
        }
        k++;
    }while(k<N);
    cout<<"El numero menor es: "<<menor<<endl;
    cout<<"El numero mayor es: "<<mayor<<endl;
    
    /*Ordenar de forma ascendente para sacar la media (Metodo de la burnuja)*/
    int aux, mitad;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(vector[j]>vector[j+1]){
                aux=vector[j+1];
                vector[j+1]=vector[j];
                vector[j]=aux;
            }
        }
    }
    mitad=N/2;
    cout<<"La media es: "<<vector[mitad]<<endl;
}


