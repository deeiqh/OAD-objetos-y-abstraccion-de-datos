/*
#include <iostream>
#include <fstream>
using std::cout;    using std::endl;
using std::string;
void readNumbers() {
    // Create our ifstream and make it open the file
    std::ifstream input("numbers.txt");
    // This will store the values as we get them form the stream
    int value;
    while(true) {
        // Extract next number from input
        input >> value;
        // If input is in a fail state, either a value couldn't
        // be converted, or we are at the end of the file.
        if(input.fail())
            break;
        cout << "Value read: " << value << endl;
    }
}
void readHaikuWord() {
    // Create our ifstream and make it open the file
    std::ifstream input("haiku.txt");
    // This will store the values as we get them form the stream
    string word;
    while(true) {
        // Extract next word from input
        input >> word;
        // If input is in a fail state, either a value couldn't
        // be converted, or we are at the end of the file.
        if(input.fail())
            break;
        cout << "Word read: " << word << endl;
    }
}
void readHaikuLine() {
    // Create our ifstream and make it open the file
    std::ifstream input("haiku.txt");
    // This will store the lines as we get them form the stream
    string line;
    while(true) {
        std::getline(input, line);
        // If input is in a fail state, either a value couldn't
        // be converted, or we are at the end of the file.
        if(input.fail())
            break;
        cout << line << endl;
        cout << line << endl;
    }
}
int main() {
    readNumbers();
    cout << "==========================" << endl;
    readHaikuWord();
    cout << "==========================" << endl;
    readHaikuLine();
    return 0;
}

*/



#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#define SENTINEL "z"

using namespace std;

void readFile(string filename);

void readFile(string filename)
{
    fstream archivo;
    archivo.open(filename,fstream::in);

    string linea;
    int count_linea = 0;
    int count_palabra = 0;
    int count_car = 0;

    while(getline(archivo,linea)){
        count_linea++;
        istringstream linea_(linea);
        string palabra;
        while(linea_>>palabra){
            count_palabra++;
            count_car += palabra.length() + 1;
        }
    }
    count_car++;

    cout << "Char count: " << count_car <<'\n';
    cout << "Word count: " << count_palabra++ <<'\n';
    cout << "Line count: " << count_linea <<'\n';

    archivo.close();
}


int main() {

    int n = 6;
    cout<< "Resultado: " << n + "4534545534534534" <<endl;

    cout << "-------" << '\n';

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



/*
#include<string>
#include<iostream>

using namespace std;

int main()
{
    int n=60;
    cout<< "Resultado: " << n + "A" <<endl;
    return 0;

}

*/


























