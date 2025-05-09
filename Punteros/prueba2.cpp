#include <iostream>
using namespace std;
/* Definición de la estructura */
struct coordenadas 
{
    float x;
    float y;
    float z;
};

int main() 
{
    /* Declaración de dos estructuras */
    struct coordenadas location1, location2;
    /* Declaración de dos punteros */
    struct coordenadas *ptr1, *ptr2;

    /* Asignación de direcciones a los punteros */
    ptr1 = &location1;
    ptr2 = &location2;

    /* Asignación de valores a la primera estructura */
    ptr1->x = 3.5;
    ptr1->y = 5.5;
    ptr1->z = 10.5;
    /* Asignacion de valores por medio de la variable
    location1.x = 3.5;
    location1.y = 5.5;
    location1.z = 10.5; */

    cout<<location1.x<<"\t"<<location1.y<<"\t"<<location1.z<<"\t"<<endl;
    /* Copia de valores a la segunda estructura */
    ptr2->x = ptr1->x;
    ptr2->y = ptr1->y;
    ptr2->z = ptr1->z;
  
    return 0;
}
