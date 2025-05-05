#include <iostream>
using namespace std;

int fibonacci(int);
void mostrarResultados(int);

int main(){
    int n;
    cout<<"Posicion de fibonacci: ";
    cin>>n;

    cout<<"Resultados:\n";
    mostrarResultados(n);

    return 0;
}

int fibonacci(int n){
    if(n==0){
        return 0;
    }else if(n==1) {
        return 1;
    }else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

void mostrarResultados(int n){
    if(n==0 || n==1){
        cout<<"La posición 1 de Fibonacci es: 1"<<endl;
        cout<<"La posición 0 de Fibonacci es: 0"<<endl;
    }else{
        cout<<"La posición "<<n<<" de Fibonacci es: f("<<n-1<<") + f("<<n-2<<")"<<endl;
    }

    if(n>=2){
        mostrarResultados(n-1);
        cout<<"La posición "<<n<<" de Fibonacci es: "<<fibonacci(n-1)<<" + "<<fibonacci(n-2)
        <<" = "<<fibonacci(n)<<endl;
    }
}