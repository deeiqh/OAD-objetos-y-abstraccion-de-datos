#include <iostream>
#include <vector>

using namespace std;

void insertion_sort_k(vector<int> &v, int k);
void imp_v(vector<int> &v);

int main() {

    vector<int> v{7,6,5,4,3,2,1,0};
    
    int k = 3;
    insertion_sort_k(v, k);
    
    imp_v(v);
    return 0;
}

void insertion_sort_k(vector<int> &v, int k)
{
    for(int i = 0; i < v.size(); i++){
        if(i <= k) // en este rango se trabaja de manera normal
            for (int j = i-1; j >= 0; j--){
                if(v[j] <= v[j+1]) break;
                swap(v[j], v[j+1]);
            }
        else{ // desde acá hay que tener en cuenta que solo se insertara en
              // las primeras k posiciones
            int l = i;
            for (int j = k-1; j >= 0; j--){// j solo considera las comparaciones
                                           // de las primeras k posiciones
                if(v[j] <= v[l]) break;
                swap(v[j], v[l]);
                l = j; //actualizo l para que trabaje solo dentro las k primeras
                       // posiciones
            }
        }            
    }
    
    // El numero de comparaciones depende de que tan ordenado esté el arreglo
    // En el mejor caso se darán O(n) comparaciones sin importar el valor de k
    //  pues se tiene que cootejar hasta el final que se tienen los k menores valores.
    // En el peor caso se hacen k(k-1) + (n-k)(k) comparaciones; es decir, es
    // k²-k+nk-k², que es O(n).
}

void imp_v(vector<int> &v)
{
    for(auto &x:v){
        cout << x << ' ';
    }
    cout << '\n';
}
