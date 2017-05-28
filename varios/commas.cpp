#include <iostream>

using namespace std;

string addCommas(string);

int main() {

    while(true){
        string digits;
        cout << "Enter a number: ";
        getline(cin, digits);
        if (digits == "") break;
        cout << addCommas(digits) << endl;
    }
    
    return 0;
}

string addCommas(string cadena)
{
    string result = "";
    int longitud = cadena.length()-1;
    while (longitud >= 0){
        int j = 0;
        while (longitud >= 0 && j != 3 ){
            result = cadena[longitud--] + result;
            j++;
        }
        if (longitud >= 0)
            result = ',' + result;
    }    
    return result;
}
