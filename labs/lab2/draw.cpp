#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std ;

void fill_region ( vector < string > & pixels , int row , int col );
void fill_region ( vector < string > & pixels , int fila , int columna )
{/*
            if (maze.isOutside(start)) return true;
            if (maze.isMarked(start)) return false;
            maze.markSquare(start);
            pause(200);
            for(Direction dir=NORTH; dir<=WEST; dir++) {
                if (!maze.wallExists(start, dir)) {
                    if (solveMaze(maze, adjacentPoint(start, dir))){
                        return true;
                    }
                }
            }
            maze.unmarkSquare(start);
            return false;
*/
    //primero determino si el pintado sera dentro o fuera
    bool abre = false;
    int pos = 0;
    bool dentro = false;
    for( char &c: pixels[fila]){
        if(c == '-'){
            if ( columna == pos && abre)
                dentro = true;
        }
        else{
            abre = !abre;            
        }
        pos++;
    }
    
    //ahora pinto segun si se determino dentro o fuera
    //guardo los intervalos de pintado y luego pinto
    int linea_= 0;
    for(string linea: pixels){
        pos = 0;
        vector<int> intervalo;
        bool busca_mas = true; // para colorear fuera
        for(char &p : linea){            
            if (dentro){
                if(p == '+') 
                    intervalo.push_back(pos);                 
            }else{                 
                if( (p == '-') && busca_mas ){ 
                    intervalo.push_back(pos);   
                }                
                if( (p == '+') ){ 
                    busca_mas = !busca_mas;
                }
            }
            pos++;            
        }
        if(!dentro)intervalo.push_back(pos);//la ultima posicion es parte del
                                                // intervalo de pintado
        
        // coloreamos los intervalo, tomando pares del vector
        
        // si hay un numero impar de + el del medio no se toma en cuenta al pintar 
        int tam_intervalo = intervalo.size();
        if (tam_intervalo%2 != 0)
                intervalo.erase(intervalo.begin() + (tam_intervalo/2) );          
        
        tam_intervalo = intervalo.size();
        for(int i = 0; i < tam_intervalo; i++){
            for(int j = intervalo[i]; j <= intervalo[i+1]; j++){
                pixels[linea_][j] = '+';
            }
            i++;
        }
        linea_++;
    }
}

int main ()
{
    vector < string > pixels ;
    string row ;
    
    fstream archivo;
    archivo.open("draw.in", fstream::in);
    
    while ( archivo >> row )
        pixels . push_back ( row );

    archivo.close();
    
    fill_region ( pixels , 3 ,6);

    for ( int i = 0; i < pixels.size(); i++)
        cout << pixels [ i ] << endl ;

    return 0;
}
