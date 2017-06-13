#include <iostream>
#include <string>

using namespace std;


struct Celda {
	int valor;
	Celda* next;
};

/* Reads in a list of values from the user and builds a linked list from them.
 * The list is in the reverse order in which the elements were added in.
 */
Celda* readList() {
    Celda* result = NULL;

    while (true) {
        int val;
        cout<<"Next entry? ";
        cin>>val;
        if (val == 0) break;

        /* Create a new cel. */
        Celda* cel = new Celda;
        cel->valor = val;

        /* Prepend it to the list. */
        cel->next = result;
        result = cel;
    }

    return result;
}

/* Recursively reads in a list of values from the user and builds a list out of them.
 * The elements will be in the order in which they were added.
 */
Celda* readListRec() {
        int val;
        cout<<"Next entry? ";
        cin>>val;
        if (val == 0) return NULL;

    /* Recursive Step: Make a new cell with this value, then fill in the rest of
     * the list recursively.
     */
    Celda* result = new Celda;
    result->valor = val;
    result->next = readListRec();
    return result;
}

/* Prints the contents of a linked list in order. */
void printList(Celda* list) {
    for (Celda* cel = list; cel != NULL; cel = cel->next) {
        cout << cel->valor << endl;
    }
    cout << "Nuuul";
}

/* Prints the contents of a linked list recursively. */
void printListRec(Celda* list) {
    /* Base Case: Empty list, nothing to print! */
    if (list == NULL) cout << "Nuuul";

    /* Recursive Step: Print the first element, then the remaining ones. */
    else{
        cout << list->valor << endl;
        printListRec(list->next);
    }
}


void stutter(Celda *lista)
{

	while(lista != NULL){
		Celda *nodo = new Celda;

		nodo->valor = lista-> valor;
		nodo->next = lista-> next;		

		lista-> next = nodo;
		
		lista = nodo->next;
	}
}

Celda *reorg(Celda *lista)
{	

	Celda *negativos = NULL;
	Celda *positivos;
	Celda *negativo = NULL;
	Celda *positivo;
	int flag_posi = true;
	int flag_nega = true;
	
	while(lista != NULL){
		if (flag_posi && (lista->valor) >= 0 ){			    
			positivos = lista;
			positivo = lista;
			flag_posi = false;
			lista = lista-> next;			
		}else{
		    if(flag_nega && (lista->valor) < 0){
		        negativos = lista;
		        negativo = lista;
		        flag_nega = false;
		        lista = lista->next;		        
		    }
		    else{
		        if((lista->valor) >= 0){
		            positivo -> next = lista;
                    positivo = positivo->next;
                    lista = lista->next;    
		        }
		        else{
		            negativo -> next = lista;
		            negativo = negativo->next;
		            lista = lista->next;
		        }
		    }	
		}
	}
	if (negativo != NULL)
	    negativo -> next = positivos;
	return negativos;
}

int contarDuplicados(Celda *lista)
{
	int cuenta = 0;
	while(lista != NULL && lista->next != NULL){
			if (lista->valor == lista->next->valor)				
				cuenta++;
			lista = lista->next;			
	}
	return cuenta;
}


int sumOfElementsIn(Celda* lista);
int ultimoElementoDe(Celda* lista);
Celda* concatena(Celda* uno, Celda* dos);
void concatena2(Celda*& uno, Celda* dos);
void ImprimeReversa(Celda* lista);

int main() {
    Celda* lista = readListRec();
    printListRec(lista);
	cout << '\n';
	
	stutter(lista);
	printListRec(lista);
	cout << '\n';	
	
	cout << contarDuplicados(lista) << "\n\n";	

	printListRec(reorg(lista));
	cout << '\n';


    return 0;
}


int sumOfElementsIn(Celda* lista)
{
	if (lista == NULL) 
		return 0;
	else
		return lista->valor + sumOfElementsIn(lista->next);
}

int ultimoElementoDe(Celda* lista)
{
	if (lista != NULL){
		if (lista->next != NULL) 
			return ultimoElementoDe(lista->next);
		return lista->valor;
	}
	cout << "Lista vacia";
}

Celda* concatena(Celda* uno, Celda* dos)
{
	
	Celda* resultado = new Celda;
	Celda* primero = resultado;
	while(uno != NULL){				
			resultado->valor = uno->valor;
			resultado->next = new Celda;
			resultado = resultado->next;
			uno = uno->next;				
	}		
	while(dos != NULL){				
			resultado->valor = dos->valor;
			resultado->next = new Celda;
			resultado = resultado->next;
			dos = dos->next;
	}
	return primero;	
}

void concatena2(Celda*& uno, Celda* dos)
{
	Celda* primero = uno;
	if(uno != NULL){	
		while(uno->next != NULL){
				uno = uno->next;
		}
		uno->next = dos;
	}
	uno = primero;
}

void ImprimeReversa(Celda* lista)
{
	if (lista == NULL) return;
   ImprimeReversa(lista->next);
   cout << lista->valor << '\n';
}
