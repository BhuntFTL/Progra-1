#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <list>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// Función para generar números aleatorios positivos
int generarNumeroAleatorio(int max = 1000) {
    return rand() % max + 1;
}

// a. Método de ordenación por Selección
void ordenarSeleccion(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (vec[j] < vec[min_idx]) {
                min_idx = j;
            }
        }
        swap(vec[i], vec[min_idx]);
    }
}

// b. Método de ordenación por Inserción
void ordenarInsercion(vector<int>& vec) {
    int n = vec.size();
    for (int i = 1; i < n; i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = key;
    }
}

// c. Método de ordenación Burbuja
void ordenarBurbuja(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (vec[j] > vec[j+1]) {
                swap(vec[j], vec[j+1]);
            }
        }
    }
}

// d. Método Comb Sort
void combSort(vector<int>& vec) {
    int n = vec.size();
    int gap = n;
    bool swapped = true;
    
    while (gap != 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;
        
        swapped = false;
        for (int i = 0; i < n-gap; i++) {
            if (vec[i] > vec[i+gap]) {
                swap(vec[i], vec[i+gap]);
                swapped = true;
            }
        }
    }
}

// e. Método Cocktail Sort / Shaker Sort
void cocktailSort(vector<int>& vec) {
    bool swapped = true;
    int start = 0;
    int end = vec.size() - 1;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; i++) {
            if (vec[i] > vec[i+1]) {
                swap(vec[i], vec[i+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
        swapped = false;
        end--;
        for (int i = end-1; i >= start; i--) {
            if (vec[i] > vec[i+1]) {
                swap(vec[i], vec[i+1]);
                swapped = true;
            }
        }
        start++;
    }
}

// f. Método Counting Sort
void countingSort(vector<int>& vec) {
    if (vec.empty()) return;
    int max = *max_element(vec.begin(), vec.end());
    int min = *min_element(vec.begin(), vec.end());
    int range = max - min + 1;
    vector<int> count(range), output(vec.size());
    for (int i = 0; i < vec.size(); i++)
        count[vec[i]-min]++;
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i-1];
    for (int i = vec.size()-1; i >= 0; i--) {
        output[count[vec[i]-min]-1] = vec[i];
        count[vec[i]-min]--;
    }
    for (int i = 0; i < vec.size(); i++)
        vec[i] = output[i];
}

// g. Método Bucket Sort
void bucketSort(vector<int>& vec) {
    if (vec.empty()) return;
    int max = *max_element(vec.begin(), vec.end());
    int min = *min_element(vec.begin(), vec.end());
    int range = max - min + 1;
    int bucketSize = 10;
    int bucketCount = range / bucketSize + 1;
    vector<vector<int>> buckets(bucketCount);

    for (int i = 0; i < vec.size(); i++) {
        int index = (vec[i] - min) / bucketSize;
        buckets[index].push_back(vec[i]);
    }
    
    for (int i = 0; i < buckets.size(); i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }
    
    int index = 0;
    for (int i = 0; i < buckets.size(); i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            vec[index++] = buckets[i][j];
        }
    }
}

// h. Método Shell Sort
void shellSort(vector<int>& vec) {
    int n = vec.size();
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = vec[i];
            int j;
            for (j = i; j >= gap && vec[j-gap] > temp; j -= gap) {
                vec[j] = vec[j-gap];
            }
            vec[j] = temp;
        }
    }
}

// i. Método Shaker Sort (alias de Cocktail Sort)
void shakerSort(vector<int>& vec) {
    cocktailSort(vec); // Es el mismo algoritmo que Cocktail Sort
}

// j. Método Gnome Sort
void gnomeSort(vector<int>& vec) {
    int n = vec.size();
    int index = 0;
    while (index < n) {
        if (index == 0) index++;
        if (vec[index] >= vec[index-1]) {
            index++;
        } else {
            swap(vec[index], vec[index-1]);
            index--;
        }
    }
}

// k. Método MergeSort (auxiliar)
void merge(vector<int>& vec, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = vec[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = vec[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

// k. Método MergeSort (principal)
void mergeSort(vector<int>& vec, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(vec, l, m);
    mergeSort(vec, m+1, r);
    merge(vec, l, m, r);
}

// l. Método Radix Sort
void radixSort(vector<int>& vec) {
    if (vec.empty()) return;
    
    int max = *max_element(vec.begin(), vec.end());
    
    for (int exp = 1; max/exp > 0; exp *= 10) {
        vector<int> output(vec.size());
        vector<int> count(10, 0);
        
        for (int i = 0; i < vec.size(); i++)
            count[(vec[i]/exp)%10]++;
        
        for (int i = 1; i < 10; i++)
            count[i] += count[i-1];
        
        for (int i = vec.size()-1; i >= 0; i--) {
            output[count[(vec[i]/exp)%10]-1] = vec[i];
            count[(vec[i]/exp)%10]--;
        }
        
        for (int i = 0; i < vec.size(); i++)
            vec[i] = output[i];
    }
}

// m. Método QuickSort (auxiliar)
int particion(vector<int>& vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;
    
    for (int j = low; j <= high-1; j++) {
        if (vec[j] < pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i+1], vec[high]);
    return i+1;
}

// m. Método QuickSort (principal)
void quickSort(vector<int>& vec, int low, int high) {
    if (low < high) {
        int pi = particion(vec, low, high);
        quickSort(vec, low, pi-1);
        quickSort(vec, pi+1, high);
    }
}

// Función para medir tiempo de ejecución en segundos con decimales
template<typename Func>
void medirTiempo(vector<int> copia, Func metodoOrdenacion, string nombre) {
    auto start = high_resolution_clock::now();
    
    metodoOrdenacion(copia);
    
    auto stop = high_resolution_clock::now();
    duration<double> tiempo = stop - start;
    
    cout << "- " << nombre << ": " << fixed << setprecision(6) << tiempo.count() << " s\n";
}

int main() {
    srand(time(0));
    vector<int> datos;
    int  n;

    
    cout << "Ingrese tamaño del vector: ";
    cin >> n;
    datos.resize(n);
    for (int i = 0; i < n; i++) {
        datos[i] = generarNumeroAleatorio();
    }    

    cout << "\nTiempos de ejecucion (en segundos):\n";
    cout << fixed << setprecision(6);
    
    // Ejecutar y medir tiempos en el orden solicitado
    medirTiempo(datos, [](vector<int> v) { ordenarSeleccion(v); }, "a. Seleccion");
    medirTiempo(datos, [](vector<int> v) { ordenarInsercion(v); }, "b. Insercion");
    medirTiempo(datos, [](vector<int> v) { ordenarBurbuja(v); }, "c. Burbuja");
    medirTiempo(datos, [](vector<int> v) { combSort(v); }, "d. Combsort");
    medirTiempo(datos, [](vector<int> v) { cocktailSort(v); }, "e. Cocktailsort");
    medirTiempo(datos, [](vector<int> v) { countingSort(v); }, "f. Countingsort");
    medirTiempo(datos, [](vector<int> v) { bucketSort(v); }, "g. Bucketsort");
    medirTiempo(datos, [](vector<int> v) { shellSort(v); }, "h. Shellsort");
    medirTiempo(datos, [](vector<int> v) { shakerSort(v); }, "i. Shakersort");
    medirTiempo(datos, [](vector<int> v) { gnomeSort(v); }, "j. Gnome sort");
    medirTiempo(datos, [](vector<int> v) { mergeSort(v, 0, v.size()-1); }, "k. Mergesort");
    medirTiempo(datos, [](vector<int> v) { radixSort(v); }, "l. RadixSort");
    medirTiempo(datos, [](vector<int> v) { quickSort(v, 0, v.size()-1); }, "m. Quicksort");

    return 0;
}