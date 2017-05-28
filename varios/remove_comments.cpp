#include <iostream>
#include <fstream>

using namespace std;

int main() {

    fstream in;
    in.open("input.txt", fstream::in);

    fstream out;
    out.open("output.txt", fstream::out | fstream::trunc);
    
    string linea;
    string resultado = "";
    bool cerrar = false;
    
    while (getline(in, linea)){         
        
        auto it = linea.begin();
        
        for(; it != linea.end(); it++){     
            
            if (!cerrar){ // si se busca abrir
                if (*it == '/' && *(it+1) == '*'){
                    it++;
                    cerrar = true;
                }else if(*it == '/' && *(it+1) == '/'){
                    resultado += '\n';
                    break;
                }  
                else{ //voy copiando los caracteres a la salida
                    resultado += *it;
                    if (it == linea.end()-1){
                        resultado += '\n';
                    }
                }
                
            }else{ // si se busca cerrar
                if (*it == '*' && *(it+1) == '/'){
                    it++;
                    cerrar = false;
                }
            }
        }
    }
    
    out << resultado;
    in.close();
    out.close();


    return 0;
}