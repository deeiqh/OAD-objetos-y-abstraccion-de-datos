#include<iostream>
#include<string>

using namespace std;

template<class T>
class Nodo{
public:   
    string cad;
    T data;
    Nodo* izq = NULL;
    Nodo* medio = NULL;
    Nodo* der = NULL;
    bool terminal = true;
public:
    Nodo():cad(""){};
    Nodo(string cad, T data):cad(cad), data(data){};
};

template<class T>
class Arbol_Patricia{
public:
    Nodo<T>* raiz = NULL;
public:
    Arbol_Patricia(){};

    void insert(string cad, T data)
    {
        insert_(raiz,cad, data);
    }

    bool find(string cad, T* data)
    {
        return find_(raiz,cad, data);
    }

    void insert_(Nodo<T>* &p, string str, T data)
    {
        /*
        inicialmente la cadena a insertar esta en resto1.
        en comun se guarda la parte comun, en resto1 el resto de la cadena del
        arbol y en resto2 lo que sobra de la cadena a insertar
        */
        if(p == NULL)
        {
                Nodo<T>* n = new Nodo<T> (str,data);
                p = n;
        }
        else
        {
            string comun="";
            string resto1="";
            string resto2="";

            int i=0;
            while(p->cad[i] == str[i] && str[i] != '\0')
            {
                comun += str[i];
                i++;
            }
            if(i == 0) // si las cadenas no tienen nada en comun
            {
                if(str.compare(p->cad) < 0)
                {
                    insert_(p->izq,str,data);
                    
                }
                else
                {
                    insert_(p->der,str,data);
                }
            }
            else // si hay un "comun"
            {
                resto1 = p->cad.substr(i);
                resto2 = str.substr(i);
                p->cad = comun;
                p->terminal = false;
                if(resto1 != "")
                {
                    Nodo<T>* n = new Nodo<T> (resto1,p->data);//*
                    n->medio = p->medio;
                    p->medio = n;
                }
                if(resto2 == "")
                {
                    p->data = data;
                    p->terminal = true;
                }
                else
                {
                    insert_(p->medio, resto2, data);
                }
            }
        }
    }
    
    bool find_(Nodo<T>* &p, string str, T* data)
    {
        if(p != NULL)
        {
            string comun="";
            string resto2="";

            int i=0;
            while(p->cad[i] == str[i] && str[i] != '\0')
            {
                comun += str[i];
                i++;
            };
            if(i == 0) // si las cadenas no tienen nada en comun
            {
                if(str.compare(p->cad) < 0)
                {
                    return find_(p->izq,str,data);
                    
                }
                else
                {
                    return find_(p->der,str,data);
                }
            }
            else // si hay un "comun"
            {            
                if(i == p->cad.length() && i == str.length())
                {
                    *data = p->data;
                    return true;
                }
                else
                {
                    resto2 = str.substr(i);
                    return find_(p->medio, resto2,data); 
                }
                               
            }
        }
        return false;
    }

};
