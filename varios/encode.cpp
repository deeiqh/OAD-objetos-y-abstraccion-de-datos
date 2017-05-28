#include <iostream>
#include <cctype>

using namespace std;

string encodeCaesarCipher(string , int );

int main() {
    int shift;
    string mensaje;

    cout << "This program encodes a message using a Caesar cipher.\n";
    cout << "Enter the number of character positions to shift: ";

    cin >> shift;
    getline(cin, mensaje);
    cout << "Enter a message: ";
    getline(cin, mensaje);

    cout << "Encoded message: " + encodeCaesarCipher(mensaje, shift);


    return 0;
}

string encodeCaesarCipher(string mensaje, int shift)
{
    string letras = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    string resultado = "";

    for(auto &c : mensaje){
        if (isalpha(c)){
            int indice;
            indice = shift + tolower(c) - 'a';
            if (indice < 0) indice = indice + 'z'+ 1 -'a'; // para rotar la lista de letras
            if (islower(c)) {
                resultado += letras[indice];
            }
            else
                resultado += toupper(letras[indice]);
        }else
            resultado += c;
    }
    return resultado;

}
