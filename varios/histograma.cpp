#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void histograma(vector<int> *);

int main() {

    fstream archivo;
    archivo.open("archivo.txt", fstream::in);
    
    vector<int> vector;
    int dato;
    while(archivo>>dato)
        vector.push_back(dato);
    
    histograma(&vector);
    
    archivo.close();
    
    return 0;
}

void histograma(vector<int> *vector)
{
    //genero el arreglo que almacena las veces a dibujar el *
    int arr[11]; // indice del 0 al 10
    for (int i = 0; i != 11; i++)
        arr[i] = 0;
    for(auto &x : *vector){
        arr[x/10]++;
    }
    
    //dibujo
    for (int i = 0; i != 11; i++){
        if (i != 10)
            cout << i << "0s: ";
        else
            cout << i << "0: ";
        if (arr[i] != 0){
            for (int j = 0; j!=arr[i]; j++)
                cout << '*';
        }
        cout << '\n';
    }
    
}
