#include <iostream>
using namespace std;

int factorial(int);

int main(int argc, const char * argv[]){
    int n;
    cout<<"Factorial de: ";
    cin>>n;
    cout<<"El factorial de "<<n<<" es: "<<factorial(n)<<endl;
    return 0;
}

int factorial(int n){
    int r=0;
    if(n==0){
        return 1;
    }else{
        cout<<"El factorial de "<<n<<" es "<<n<<" * f("<<n-1<<")\n";
        r=factorial(n-1);
        cout<<"El f("<<n-1<<")= "<<r<<endl;
        cout<<"El factorial de "<<n<<" es "<<n<<"*"<<r<<endl;
        return n*r;
    }
}
