#include <iostream>
#include <fstream>

using namespace std;

int main() {

    fstream archivo;
    archivo.open("lineas.txt", fstream::in);
    
    string linea, resultado;
    int longitud = 0;
    while (archivo>>linea){
        if (linea.length() > longitud){
            resultado = linea;
            longitud = resultado.length();
        }        
    }
    
    cout << resultado << '\n';
    
    return 0;
}