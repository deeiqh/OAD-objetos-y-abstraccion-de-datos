#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int nombreExc = 1;
int archExc = 2;
int cargaExc = 3;
int cierraExc  = 4;

int leeArch = 5;

int IntentaLeer = 6;

void leeArchivo ( int v [] ) {
	char *n;
	int cod;
	FILE *p;
	
	try{
		if(!leeNombreArch( n ))
			throw nombreExc;
	}
	catch(int nombreExc){
		cerr << "nombre inv";
		throw leeArch;
	}
	
	try{
		if(!abreArch(n, p))
			throw IntentaLeer;
	}
	catch(int archExc){
		cerr << "archivo inexistente";
		throw IntentaLeer ;
	}
	
	try{
		if(!cierraArch (p))
			throw cierraExc;
	}
	catch(int cierraExc){
		cerr << "archivo inexistente";
		throw IntentaLeer ;
	}

}

void intentaLeer (int v [ ] ) {
	int cod;
	do {
		cod = leeArchivo(v);
		if (cod == -1) {
			if ( !continua ( ) )
			return cod;
		} else {
			return cod;
		}
	} while (1);
}

main ( ) {
	int cod;
	int vec [100];
	cod = intentaLeer (vec);
	switch (cod) {
	case 0: break;
	case -1: printf ("error de nombre");
	 	break;
	case -2: printf ("error de carga");
		break;
	case -3: printf("error de cierre");
	};
	ordena (vec);
	imprime (vec);
}

