#include <iostream>
#include <map>

using namespace std;

int main()
{
    int dato;
    map<int, int> mapa;
    cin >> dato;
    do{
        if(mapa.find(dato) == mapa.end())
            mapa[dato] = 1; //mapa[1] es el 10 del histograma
        else
            mapa[dato]++;
        cin >> dato;
    }while(dato != -1);

    for(auto it = mapa.begin(); it != mapa.end(); it++){
        cout << it->first << ": ";
        for(int i = 0; i!=it->second; i++){
            cout << "*";
        }
        cout << '\n';
    }

    return 0;
}
