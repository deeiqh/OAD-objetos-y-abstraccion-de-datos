#include <iostream>
using namespace std;

void linea_pascal(int);

int main() {

    linea_pascal(30);	
    
    return 0;
}

void linea_interna(int, int, int, int, int[], int[]);
void imprime_nuevo_arreglo(int[],int);
void copiar_arreglos(int[], int[], int);
int linea_anterior[100];
int nuevo_arreglo[100]; //linea_nueva
void linea_pascal(int n)
{
    if ( n==1){        
        linea_anterior[0] = 1;
        cout << linea_anterior[0] << "\n";

    }else{
        
        linea_pascal(n-1);
        
        nuevo_arreglo[0] = 1;
        nuevo_arreglo[n-1] = 1;

        int i, j, k, longitud_interna;
        i = 0; j = 1; longitud_interna = n-2; k = 1;
        linea_interna(i,j,k, longitud_interna, linea_anterior, nuevo_arreglo); //modifica, si hay que, el nuevo_arreglo

        imprime_nuevo_arreglo(nuevo_arreglo, n); // imprime de forma recursiva        
        cout << "\n";
        
        copiar_arreglos(linea_anterior, nuevo_arreglo, n); //linea_anterior = nuevo_arreglo
    }
}

void linea_interna(int i, int j, int k, int longitud_interna, int linea_anterior[], int nuevo_arreglo[])
{
    if (longitud_interna != 0) { // si longitud_interna es 0, no hacer nada

        nuevo_arreglo[k] = linea_anterior[i] + linea_anterior[j];
        i++; j++; k++; longitud_interna--;
        linea_interna(i, j, k, longitud_interna, linea_anterior, nuevo_arreglo);

    }        
}

void imprime_nuevo_arreglo(int arr[],int n)
{
    if ( n == 1) cout << arr[0];
    else{
        cout << *arr << ' ';
        imprime_nuevo_arreglo(++arr, n-1);
    }
}

void copiar_arreglos(int arrA[], int arrB[], int n)
{
    if ( n == 1) arrA[0] = arrB[0];
    else{
        *arrA = *arrB;
        copiar_arreglos(++arrA, ++arrB, n-1);
    }
    
}










