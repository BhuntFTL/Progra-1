#include <iostream>
using namespace std;

int multiplicarPorSumas(int, int);

int main(){
    int num1, num2, resultado;
    cout<<"Introduce el primer número: ";
    cin>>num1;
    cout<<"Introduce el segundo número: ";
    cin>>num2;

    cout<<"Proceso de cálculo:\n";
    resultado=multiplicarPorSumas(num1, num2);
    cout<<"El resultado de "<<num1<<" x "<<num2<<" es: "<<resultado<<endl;

    return 0;
}

int multiplicarPorSumas(int a, int b){
    int r=0;
    if (b==0){
        cout<<a<<"*"<<b<<" es: 0"<<endl;
        return 0;
    }else if(b==1){
        cout<<a<<"*"<<b<<" es: "<<a<<endl;
        return a;
    }else{
        cout<<a<<"*"<<b<<" es: "<<a<<" + "<<a<<"*"<<(b-1)<<endl;
        r=a+multiplicarPorSumas(a, b - 1);
        cout<<a<<"*"<<b<<" es: "<<a<<"+"<<r-a<<" = "<<r<<endl;
        return r;
    }
}