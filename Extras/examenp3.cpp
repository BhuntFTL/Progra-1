#include <iostream>
using namespace std;
#define SIZE 100
/* Información sobre la celda */
struct informacion_celda 
{
    char nombre[SIZE];                /* Nombre de la celda */
    unsigned int identificador;      /* Número identificador */
    float calidad_senal;              /* Calidad de la señal (entre 0 y 100) */
    struct informacion_operador *ptr_operador; /* Puntero a una segunda estructura */
};

/* Información sobre el operador */
struct informacion_operador 
{
    char nombre[SIZE];           /* Cadena de texto con el nombre */
    unsigned int prioridad;     /* Prioridad de conexión */
    unsigned int ultima_comprob; /* Fecha de la última comprobación */ 
};

int main(){
    informacion_celda variable,*ptr1,*ptr2;
    informacion_celda *var2;
    informacion_operador *i1,*i2;
    cout<<sizeof(ptr1)<<endl;
    cout<<sizeof(ptr2)<<endl;
    cout<<sizeof(i1)<<endl;
    cout<<sizeof(i2)<<endl;
}