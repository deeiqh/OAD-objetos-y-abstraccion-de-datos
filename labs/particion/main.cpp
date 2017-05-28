#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &v);
int b_binaria(int x, vector<int> &v, int low, int high); 
    //con retorno de indice del valor inmediato menor al buscado, si no lo encuentra
bool particionable(vector<int> &v); 

int main() {

    vector<int> v{1,4,5,6};
    insertion_sort(v);
    
    if (particionable(v)) // se usa busqueda binaria para tener un tiempo
                          // de ejecucion mas rapido
        cout << "particionable";
    else
        cout << "no particionable";
       
    return 0;
}
bool particionable(vector<int> &v)
{
    int suma = 0;
    for(auto &x: v)
        suma += x;
    
    if (suma%2 != 0) return false;//suma impar descarta particion
    
    int semisuma = suma/2;
    int indice_ultimo = v.size()-1;
    int ultimo = v[indice_ultimo];
    if(ultimo == semisuma)
        return true; // si el mayor valor es una particion.
                     // Tomo el mayor pues está mas cerca al valor de la suma/2
    
    int falta = semisuma - ultimo;
        //es lo que falta al mayor para completar la semisuma pues
        //en este punto el mayor no es igual a la semisuma           
    while(falta != 0 && indice_ultimo != -1){        
        int indice_probable = b_binaria(falta, v, 0, indice_ultimo);
            //es el indice del numero más cercano al que falta, por ejemplo:
            // si se tiene [2,3,5,6] y falta un 4, el indice sera el del 3
            // pues 5 ya excede a 4.
        if(v[indice_probable] == falta) return true;
            //si hay un numero menor que completa la que falta se retorna
        indice_ultimo = indice_probable - 1;
            // se sigue buscando lo que falta sin tener en cuenta el utlimo numero 
            // analizado
        falta -= v[indice_probable];
            //como no se tiene en cuenta el numero analizado se descuenta a lo que falta
    }
    return false;

}

int b_binaria(int x, vector<int> &v, int low, int high)
{
    int medio = (high-low)/2 + low;
    if(v[medio] == x || (low == high)) 
        return medio; //medio == low, asi retorna el indice que queremos si no encuentra
                      // el numero buscado
    else{
        if (v[medio] < x) 
            return b_binaria(x,v,medio+1, high);
        else
            return b_binaria(x,v,low,medio-1);
    }
}

void insertion_sort(vector<int> &v)
{
    for(int i = 0; i != v.size(); i++){
        for (int j = i; j > 0; j--){
            if(v[j] >= v[j-1]) break;
            swap(v[j], v[j-1]);
        }
    }
}



