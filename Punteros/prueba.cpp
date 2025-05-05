#include <iostream>
using namespace std;
int main(){
    int num1, num2;
    int *ptr1, *ptr2;
    //apuntamos los punteros a las variables
    ptr1=&num1;
    ptr2=&num2;
    //asignamos valores a las variables
    num1=10;
    num2=20;
    //cambiamos la direccion de los punteros
    ptr1=ptr2;
    ptr2=NULL;
    //mostrar contenido de los punteros con el *
    cout<<*ptr1<<endl;
    cout<<*ptr2<<endl;

}