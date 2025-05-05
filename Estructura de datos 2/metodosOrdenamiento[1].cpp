/* 
 * Métodos de ordenamiento implementados:
 * a. Selección
 * b. Inserción
 * c. Burbuja
 * d. Combsort
 * e. Cocktailsort
 * f. Countingsort (Ordenación por cuentas)
 * g. Binsort/Bucketsort (Clasificación por urnas o casilleros)
 * h. Shellsort
 * i. Shakersort (sacudida)
 * j. Gnome sort
 * k. Mergesort
 * l. RadixSort
 * m. Quicksort
 */

 #include <iostream>
 #include <ctime>
 #include <cstdlib>
 
 using namespace std;
 
 // Prototipos de funciones
 void seleccion(int vec[], int n);
 void inserccion(int vec[], int n);
 void burbuja(int vec[], int n);
 void combsort(int vec[], int n);
 void cocktailsort(int vec[], int n);
 void countingsort(int vec[], int n);
 void binsort(int vec[], int n);
 void shell(int vec[], int n);
 void shakersort(int vec[], int n);
 void gnome(int vec[], int n);
 void mergesort(int vec[], int n);
 void radixsort(int vec[], int n);
 void quicksort(int vec[], int n);
 
 int main() {
     srand(time(NULL));
     int n = 0;
     
     cout << "Ingresa el tamaño del arreglo: ";
     cin >> n;
     
     int vec[n];
     
     cout << "Arreglo desordenado: " << endl;
     for (int i = 0; i < n; i++) {
         vec[i] = rand() % 1000;
         cout << vec[i] << " ";
     }
     cout << endl << endl << endl;
 
     // Llamada a los métodos de ordenamiento
     seleccion(vec, n);
     inserccion(vec, n);
     burbuja(vec, n);
     combsort(vec, n);
     cocktailsort(vec, n);
     countingsort(vec, n);
     binsort(vec, n);
     shell(vec, n);
     shakersort(vec, n);
     gnome(vec, n);
     mergesort(vec, n);
     radixsort(vec, n);
     quicksort(vec, n);
 
     return 0;
 }
 
 // Implementación de los métodos de ordenamiento
 
 void seleccion(int vec[], int n) {
     int i, j, min, aux;
     
     for (i = 0; i < n - 1; i++) {
         min = i;
         cout << "El menor elemento es: " << vec[min] << endl;
         
         for (j = i + 1; j < n; j++) {
             if (vec[j] < vec[min]) {
                 cout << "El menor elemento es: " << vec[j] << endl;
                 min = j;
             }
         }
         
         if (min != i) {
             cout << "Intercambiando " << vec[i] << " y " << vec[min] << endl;
             aux = vec[i];
             vec[i] = vec[min];
             vec[min] = aux;
         }
     }
     
     cout << "Arreglo ordenado por seleccion: " << endl;
     for (int i = 0; i < n; i++) {
         cout << vec[i] << " ";
     }
     cout << endl << endl;
 }
 
 void inserccion(int vec[], int n) {
     int i, j, aux;
     
     for (i = 1; i < n; i++) {
         cout << "El elemento a insertar es: " << vec[i] << endl;
         aux = vec[i];
         j = i - 1;
         
         while (j >= 0 && vec[j] > aux) {
             cout << "Desplazando " << vec[j] << " a la derecha" << endl;
             vec[j + 1] = vec[j];
             j--;
         }
         
         cout << "Colocando " << aux << " en la posicion " << j + 1 << endl;
         vec[j + 1] = aux;
     }
     
     cout << "Arreglo ordenado por insercion: " << endl;
     for (int i = 0; i < n; i++) {
         cout << vec[i] << " ";
     }
     cout << endl << endl;
 }
 
 void burbuja(int vec[], int n) {
     int aux;
     bool bandera;
 
     for (int i = 1; i < n; i++) {
         bandera = false;
         
         for (int j = n - 1; j >= i; j--) {
             if (vec[j - 1] > vec[j]) {
                 cout << "Comparando " << vec[j] << " y " << vec[j - 1] << endl;
                 cout << "Intercambiando " << vec[j] << " y " << vec[j - 1] << endl;
                 aux = vec[j - 1];
                 vec[j - 1] = vec[j];
                 vec[j] = aux;
                 bandera = true;
             }
         }
         
         if (bandera == false) break;
     }
 
     cout << "Arreglo ordenado por burbuja: " << endl;
     for (int i = 0; i < n; i++) {
         cout << vec[i] << " ";
     }
     cout << endl << endl;
 }
 
 void combsort(int vec[], int n) {
     int i, j, aux;
     float factor = 1.3;
     int salto = n / factor;
     bool bandera = true;
 
     while (salto > 1 || bandera == true) {
         bandera = false;
         
         for (i = 0; i < n - salto; i++) {
             cout << "Comparando " << vec[i] << " y " << vec[i + salto] << endl;
             j = i + salto;
             
             if (vec[i] > vec[j]) {
                 cout << "Intercambiando " << vec[i] << " y " << vec[j] << endl;
                 aux = vec[i];
                 vec[i] = vec[j];
                 vec[j] = aux;
                 bandera = true;
             }
         }
         
         cout << "Reduciendo el salto a " << salto << "/" << factor << endl;
         salto /= factor;
     }
 
     cout << "Arreglo ordenado por combsort: " << endl;
     for (int i = 0; i < n; i++) {
         cout << vec[i] << " ";
     }
     cout << endl << endl;
 }
 
 void cocktailsort(int vec[], int n) {
     int i, aux;
     bool bandera = true;
     
     while (bandera == true) {
         bandera = false;
         
         for (i = 0; i < n - 1; i++) {
             if (vec[i] > vec[i + 1]) {
                 cout << "Comparando " << vec[i] << " y " << vec[i + 1] << endl;
                 cout << "Intercambiando " << vec[i] << " y " << vec[i + 1] << endl;
                 aux = vec[i];
                 vec[i] = vec[i + 1];
                 vec[i + 1] = aux;
                 bandera = true;
             }
         }
         
         if (bandera == false) break;
         
         bandera = false;
         
         for (i = n - 1; i > 0; i--) {
             if (vec[i] < vec[i - 1]) {
                 cout << "Comparando " << vec[i] << " y " << vec[i - 1] << endl;
                 cout << "Intercambiando " << vec[i] << " y " << vec[i - 1] << endl;
                 aux = vec[i];
                 vec[i] = vec[i - 1];
                 vec[i - 1] = aux;
                 bandera = true;
             }
         }
     }
 
     cout << "Arreglo ordenado por cocktailsort: " << endl;
     for (int i = 0; i < n; i++) {
         cout << vec[i] << " ";
     }
     cout << endl << endl;
 }
 
 void countingsort(int vec[], int n) {
     int i, j, k = 0;
     int max = vec[0];
     
     for (i = 1; i < n; i++) {
         if (vec[i] > max) {
             cout << "El nuevo maximo es: " << vec[i] << endl;
             max = vec[i];
         }
     }
     
     int *count = new int[max + 1];
     
     for (i = 0; i < max + 1; i++) {
         cout << "El conteo de " << i << " es: " << count[i] << endl;
         count[i] = 0;
     }
     
     for (i = 0; i < n; i++) {
         cout << "Contando " << vec[i] << " en la posicion " << i << endl;
         count[vec[i]]++;
     }
     
     for (i = 0; i < max + 1; i++) {
         for (j = 0; j < count[i]; j++) {
             cout << "El conteo de " << i << " es: " << count[i] << endl;
             cout << "Colocando " << i << " en la posicion " << k << endl;
             vec[k++] = i;
         }
     }
 
     cout << "Arreglo ordenado por countingsort: " << endl;
     for (int i = 0; i < n; i++) {
         cout << vec[i] << " ";
     }
     cout << endl << endl;
     
     delete[] count;
 }
 
 void binsort(int vec[], int n) {
     int i, j, k = 0;
     int max = vec[0];
     
     for (i = 1; i < n; i++) {
         if (vec[i] > max) {
             cout << "El nuevo maximo es: " << vec[i] << endl;
             max = vec[i];
         }
     }
     
     int *bins = new int[max + 1];
     
     for (i = 0; i < max + 1; i++) {
         cout << "El conteo de " << i << " es: " << bins[i] << endl;
         cout << "Inicializando el conteo de " << i << " a 0" << endl;
         bins[i] = 0;
     }
     
     for (i = 0; i < n; i++) {
         cout << "Contando " << vec[i] << " en la posicion " << i << endl;
         cout << "El conteo de " << vec[i] << " es: " << bins[vec[i]] << endl;
         bins[vec[i]]++;
     }
     
     for (i = 0; i < max + 1; i++) {
         for (j = 0; j < bins[i]; j++) {
             cout << "El conteo de " << i << " es: " << bins[i] << endl;
             cout << "Colocando " << i << " en la posicion " << k << endl;
             vec[k++] = i;
         }
     }
 
     cout << "Arreglo ordenado por binsort: " << endl;
     for (int i = 0; i < n; i++) {
         cout << vec[i] << " ";
     }
     cout << endl << endl;
     
     delete[] bins;
 }
 
 void shell(int vec[], int n) {
     int i, j, aux;
     int salto = n / 2;
     
     while (salto > 0) {
         cout << "El salto es: " << salto << endl;
         
         for (i = 0; i < n - salto; i++) {
             j = i + salto;
             
             while (j < n) {
                 if (vec[i] > vec[j]) {
                     cout << "Comparando " << vec[i] << " y " << vec[j] << endl;
                     cout << "Intercambiando " << vec[i] << " y " << vec[j] << endl;
                     aux = vec[i];
                     vec[i] = vec[j];
                     vec[j] = aux;
                 }
                 j += salto;
             }
         }
         salto /= 2;
     }
 
     cout << "Arreglo ordenado por shell: " << endl;
     for (int i = 0; i < n; i++) {
         cout << vec[i] << " ";
     }
     cout << endl << endl;
 }
 
 void shakersort(int vec[], int n) {
     int i, aux;
     bool bandera = true;
     
     while (bandera == true) {
         bandera = false;
         
         for (i = 0; i < n - 1; i++) {
             if (vec[i] > vec[i + 1]) {
                 cout << "Comparando " << vec[i] << " y " << vec[i + 1] << endl;
                 cout << "Intercambiando " << vec[i] << " y " << vec[i + 1] << endl;
                 aux = vec[i];
                 vec[i] = vec[i + 1];
                 vec[i + 1] = aux;
                 bandera = true;
             }
         }
         
         if (bandera == false) break;
         
         bandera = false;
         
         for (i = n - 1; i > 0; i--) {
             cout << "El elemento " << vec[i] << " es menor que el elemento " << vec[i - 1] << endl;
             
             if (vec[i] < vec[i - 1]) {
                 cout << "Comparando " << vec[i] << " y " << vec[i - 1] << endl;
                 cout << "Intercambiando " << vec[i] << " y " << vec[i - 1] << endl;
                 aux = vec[i];
                 vec[i] = vec[i - 1];
                 vec[i - 1] = aux;
                 bandera = true;
             }
         }
     }
 
     cout << "Arreglo ordenado por shakersort: " << endl;
     for (int i = 0; i < n; i++) {
         cout << vec[i] << " ";
     }
     cout << endl << endl;
 }
 
 void gnome(int vec[], int n) {
     int i = 0, aux;
     
     while (i < n) {
         if (i == 0 || vec[i - 1] <= vec[i]) {
             cout << "El elemento " << vec[i] << " es mayor que el elemento " << vec[i - 1] << endl;
             i++;
         } else {
             cout << "Intercambiando " << vec[i] << " y " << vec[i - 1] << endl;
             aux = vec[i];
             vec[i] = vec[i - 1];
             vec[i - 1] = aux;
             i--;
         }
     }
 
     cout << "Arreglo ordenado por gnome: " << endl;
     for (int i = 0; i < n; i++) {
         cout << vec[i] << " ";
     }
     cout << endl << endl;
 }
 
 void mergesort(int vec[], int n) {
     if (n < 2) return;
     
     int m = n / 2;
     mergesort(vec, m);
     cout << "mergesort(" << vec + m << "," << n - m << ")" << endl;
     mergesort(vec + m, n - m);
     cout << "Llamando a mergesort(" << vec + m << "," << n - m << ")" << endl;
     
     int i = 0, j = m, k = 0;
     int *w = new int[n];
     
     while (i < m && j < n) {
         if (vec[i] < vec[j]) {
             w[k++] = vec[i++];
         } else {
             w[k++] = vec[j++];
         }
     }
     
     while (i < m) {
         w[k++] = vec[i++];
     }
     
     while (j < n) {
         w[k++] = vec[j++];
     }
     
     for (int i = 0; i < n; i++) {
         vec[i] = w[i];
     }
     
     delete[] w;
 
     cout << "Arreglo ordenado por mergesort: " << endl;
     for (int i = 0; i < n; i++) {
         cout << vec[i] << " ";
     }
     cout << endl << endl;
 }
 
 void radixsort(int vec[], int n) {
     int i, max = vec[0];
     
     for (i = 1; i < n; i++) {
         if (vec[i] > max) {
             cout << "El nuevo maximo es: " << vec[i] << endl;
             max = vec[i];
         }
     }
     
     int exp = 1;
     
     while (max / exp > 0) {
         int *output = new int[n];
         int count[10] = {0};
         
         for (i = 0; i < n; i++) {
             count[(vec[i] / exp) % 10]++;
         }
         
         for (i = 1; i < 10; i++) {
             count[i] += count[i - 1];
         }
         
         for (i = n - 1; i >= 0; i--) {
             output[count[(vec[i] / exp) % 10] - 1] = vec[i];
             count[(vec[i] / exp) % 10]--;
         }
         
         for (i = 0; i < n; i++) {
             vec[i] = output[i];
         }
         
         exp *= 10;
         delete[] output;
     }
 
     cout << "Arreglo ordenado por radixsort: " << endl;
     for (int i = 0; i < n; i++) {
         cout << vec[i] << " ";
     }
     cout << endl << endl;
 }
 
 void quicksort(int vec[], int n) {
     int i, j, x, y;
     i = 0;
     j = n - 1;
     x = vec[n / 2];
     
     do {
         while (vec[i] < x) i++;
         while (vec[j] > x) j--;
         
         if (i <= j) {
             y = vec[i];
             vec[i] = vec[j];
             vec[j] = y;
             i++;
             j--;
         }
     } while (i <= j);
     
     if (j > 0) quicksort(vec, j + 1);
     if (i < n) quicksort(&vec[i], n - i);
 
     cout << "Arreglo ordenado por quicksort: " << endl;
     for (int i = 0; i < n; i++) {
         cout << vec[i] << " ";
     }
     cout << endl << endl;
 }