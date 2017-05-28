#include <iostream>
#include <vector>

using namespace std;

void sort(int *array, int n);
void merge(int *array, int *a1, int a1_size, int *a2, int a2_size);
int main() {

    int a[] = {5,3,0,2,1,4,7,9,8,6};
        
    sort(a,10);

    for(auto &x:a)
        cout << x << ' ';
    
    return 0;
}

void sort(int *array, int n)
{
    if (n <= 1) return;
    
    int a1[(n/2) +1];
    int a1_size = 0;
    
    int a2[(n/2) +1];
    int a2_size = 0;
    
    int a1_p = 0; // indice que controla los push_back del vector emulado
    int a2_p = 0;
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            a1[a1_p] = array[i];
            a1_p++;
            a1_size++;
        } else {
            a2[a2_p] = array[i];
            a2_p++;
            a2_size++;
        }
    }
    sort(a1,a1_size);
    sort(a2,a2_size);
    merge(array, a1, a1_size, a2, a2_size);
} 

void merge(int *array, int *a1, int a1_size, int *a2, int a2_size) {
    int p1 = 0;
    int p2 = 0;
    int i = 0;
    while (p1 < a1_size && p2 < a2_size) {
        if (a1[p1] < a2[p2]) {
            array[i] = a1[p1++];
        } else {
            array[i] = a2[p2++];
        }
        i++;
    }
    while (p1 < a1_size){
        array[i] = a1[p1++];
        i++;
    }
    while (p2 < a2_size){
        array[i] = a2[p2++];
        i++;
    }
}