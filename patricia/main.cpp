#include "arbol_patricia.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

int main()
{
    struct pos
    {
        int fila;
        int columna;
    };
    
    //el texto lo subimos a un buffer
    fstream arch;
    arch.open("texto.txt", fstream::in);
    
    arch.seekg(0,fstream::end);
    size_t lon = arch.tellg();
    char buffer[lon];
    arch.seekg(0);
    arch.read(buffer, lon);

    //procesamos el buffer al arbol patricia
    size_t f, c, i;
    f = 0;
    c = 0;
    i = 0;
    string palabra("");
    set<char> simbolos;
    simbolos.insert(' ');
    simbolos.insert(',');
    simbolos.insert('.');
    simbolos.insert('\t');
    simbolos.insert('\n');
    Arbol_Patricia<pos> p; 
    while(i <= lon-1)
    {
        for(;simbolos.find(buffer[i]) == simbolos.end();i++,c++)
       {
            palabra += buffer[i];  
        }       
        
        //---fila y columna se guardan junto a la palabra en el arbol patricia
        // Por ahora se muestra la fila y clmna de la última ocurrencia de la palabra               
        pos data;        
        data.fila = f+1;
        data.columna = c+1-palabra.length();        
        p.insert(palabra,data);        
        palabra.clear();
        //---
        
        for(;simbolos.find(buffer[i]) != simbolos.end();i++)
        {
            c++;
            if(buffer[i] == '\n')
            {
                f++;
                c = 0;
            }
        }        
    }
    arch.close();
    pos data2;
    string cad = "of";
    if (p.find(cad,&data2))
    {
        cout <<cad<<"*"<<data2.fila<<"-"<<data2.columna<<'\n';
    }
    
    return 0;
}

/*
Arbol_Patricia<int> p;
    p.insert("aminoacido",1);
    p.insert("amino",2);
    p.insert("amigo",3);
    p.insert("amiga",3);
    p.insert("viento",5);
    p.insert("vivir",6);
    p.insert("ver",7);
    p.insert("vicio",8);
    p.insert("cachorro",9);
    p.insert("can",10);
    p.insert("canguro",11);
    
    //cerr << p.raiz->der->medio->medio->izq->data;
    int data;
    if (p.find("vivir",&data))
    {
        cout << data;
    }
*/
