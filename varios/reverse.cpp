#include <iostream>
#include <string>
using namespace std;

string reverse(string);

int main() {
    string cadena = "odsfdr";
    cout << reverse(cadena);	
    
    return 0;
}

int boo = 0;
int i, j;
string reverse(string cadena)
{   
    if (boo == 0){
        i = 0;
        j = cadena.length() - 1;
        boo = 1;
    }
    if (i < j){
        char aux = cadena[j];
        cadena[j] = cadena[i];
        cadena[i] = aux;
        i++;
        j--;
        return reverse(cadena);        
    }   
    
    return cadena;
}