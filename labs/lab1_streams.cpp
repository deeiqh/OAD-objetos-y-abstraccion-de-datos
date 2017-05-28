#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#define SENTINEL "no"

using namespace std;


void readFile(string filename);
int decimalPlaces(int);


/* Function: readFile(string filename);
 * ------------------------------------
 * Read the file and print out the file statistics.
 */
void readFile(string filename)
{
    int cant_lineas = 0;
    int cant_palabras = 0;
    int cant_caracteres = 0;
    
    ifstream archivo(filename + ".txt");
    string word;

    string line_;
    istringstream line;
    while(getline(archivo, line_)){
        line.str(line_);
        cant_lineas++;
        string word;
        while(line){
            line >> word;
            cout << "palabras:  " << word << '\n';
            cant_palabras++;
            cant_caracteres += word.length() +1;
        }        
        line.clear();        
    }
    
    cout << cant_caracteres << '\n';
    cout << cant_palabras << '\n';
    cout << cant_lineas << '\n';
    
    archivo.close();
    archivo.clear();
}

/*
 * Function: int decimalPlaces(int number);
 * ----------------------------------------
 * Return the "size" of the int, e.g., if number is
 * "9" we return "1", if number is "415" we return "3",
 * if number is "1000000" we return "7".
 */
int decimalPlaces(int number)
{
}


int main() {

    string filename;
    while ( true ) {
        cout<< "Enter a filename: " ;
        cin>>filename;
        //filename = getLine("Enter a filename: ");
        if ( filename == SENTINEL ) break;
        readFile(filename);
        cout << endl;
    }

    return 0;
}
