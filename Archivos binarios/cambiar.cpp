/*
    Clase del dia 28 de mayo del 2025

    ARCHIVOS BINARIOS (MODIFICAR)

    Recordar que el los archivos de texto necesitabamos un temporal
    para copear los datos que no me interesan, pero el que si me interesa,
    lo modifico y despues lo mando a temporal y se reenombraba temporal
    para que fuera el principal

    POR OTRA PARTE, en los archivos BINARIOS no se necesita un temporal
    pues en los binarios podemos modificar la estructura en el mismo archivo
    (debido a que es como un cd, hay un identidicador de linea, y solo se
    modifica la linea)

        "rb+" Se puede leer en forma secuencial o solo un renglon
        tambien se puede grabar de forma secuencial o solo en un renglon

        se usara 
            - fread
            - fwrite, 
            -fseek (coloca el puntero en el registro a modificar)

*/
//------------------------------------LIBRERIAS---------------------------------------
#include <iostream>
using namespace std;

//------------------------------------DATOS GLOBALES----------------------------------
struct Hotel
{
    int numHab;
    char nomHuesped[25];
    int dias;
    float costo;
    bool estado;
};
//--------------------------------Prototipo de funciones------------------------------

//--------------------------------Programa principal----------------------------------
int main()
{

    FILE *archHotel; // Declarar archivo
    Hotel huesped;   // Variable tipo struct
    int numHabitacion = 0;
    bool encontrada = false;

    // Abrir archivo (lectura y escritura)
    archHotel = fopen("Huespedes.bin", "rb+");

    // Verificar archivo
    if (archHotel == NULL)
    {
        cout << endl
             << "Error en la apertura";
        return 1; // salir
    }

    // Captura el numero de habiatacion a buscar
    cout << endl
         << "Habitacion a modificar: ";
    cin >> numHabitacion;

    // Leemos contenido (mientras haya que leer)
    while (fread(&huesped, sizeof(Hotel), 1, archHotel))
    {
        if (huesped.numHab == numHabitacion)
        { // Si existe la habitacion
            encontrada = true;
            // Mostrar el contenido
            cout<<endl<<"Habitacion actual"<<endl;
            cout << "Numero de habiatacion: " << huesped.numHab << endl;
            cout << "Nombre del huesped: " << huesped.nomHuesped << endl;
            cout << "Dias de hospedaje: " << huesped.dias << endl;
            cout << "Costo por dia: $" << huesped.costo << endl;
            // Capturar datos a modificar
            cout<<endl<<"Modificar los siguiente..."<<endl;
            cout << "Dias de hospedaje: ";
            cin >> huesped.dias;
            cout << "Costo por dia: $";
            cin >> huesped.costo;
            //Colocar puntero en el registro a modificar
            /*  Parametros para seek
                1-.variable de tipo archivo
                2-.tamaño de la estructura
                3-.lugar a partir de donde se toma el registro: 
                    SEEK_CUR (current-donde esta)
                    SEEK_SET (set- al inicio)
                    SEEK_END (end- al final)
            */
            fseek(archHotel,-sizeof(Hotel),SEEK_CUR); //IMPORTANTE EL MENOS (SE coloca antes de la estructura y no despues de la estructura, si no lo repite)
            //Grabamos los datos (en el apuntador antes colocado)
            fwrite(&huesped,sizeof(Hotel),1,archHotel);

            break;
        }
    }
    // Cerrar el archivo
    fclose(archHotel);

    if(!encontrada){
        cout<<endl<<"Numero de habitacion no existe";
    }

    return 0;
}