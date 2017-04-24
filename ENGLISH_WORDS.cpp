#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main()
{
    fstream archivo;
    archivo.open("english_words.txt", fstream::in);

    map<int, int> mapa;
    string word;
    while(archivo>>word){
        int longitud = word.length();
        if (mapa.find(longitud) == mapa.end()){
            mapa[longitud] = 1;
        }
        else
            mapa[longitud]++;
    }

    for(auto it = mapa.begin(); it != mapa.end(); it++){
        cout << it->first << " " << it->second << '\n';
    }
    archivo.close();

    return 0;
}
