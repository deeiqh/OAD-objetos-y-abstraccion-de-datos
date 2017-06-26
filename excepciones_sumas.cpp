#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int Fin_entrada = 1;
int Mal_rango = 2;
int Over = 3;
int Illegal  = 4;

int suma_cuadrados(vector<int>);

int main()
{
	vector<int> lista;
	cout << suma_cuadrados(lista);
	cout << '\n';
	return 0;
}

int suma_cuadrados(vector<int> v)
{
	int a;
	int suma = 0;
	
	try{
		
		while(cin >> a){
			try{
				if(a >= -100 && a<=100){
					suma += a*a;
					try{
						if(suma <= INT_MIN || a>=INT_MAX)
							throw Over;
					}
					catch (int Over){
						cerr << "Over";
					}					
				}else{
					if (a == -111){
						try{
							throw Fin_entrada;
						}					
						catch(int Fin_entrada){
							cerr << "Fin_entrada\n";
							return suma;
						}
					}else
						throw Mal_rango;
				}
				
			}	
			catch (int Mal_rango){
				cerr << "Mal_rango";
			}		
		}
		throw Illegal;
	}
	catch (int Illegal){
		cerr << "Ilegal";	
	}	
	 
}
