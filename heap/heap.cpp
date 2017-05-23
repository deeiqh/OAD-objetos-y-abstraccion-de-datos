#include "heap.h"
#include <iostream>
#include <cmath>

/* Starting size for the heap.*/
const int DEFAULT_SIZE = 9;

Heap::Heap() {
    allocatedLength = DEFAULT_SIZE;
    n = 0;
    T = new int[allocatedLength];
}

Heap::~Heap() {
	delete[] T;
}

/* Retorna el número de elementos de la cola de prioridad. */
int Heap::size() {
    return n;
}

bool Heap::isEmpty() {
    return (size() == 0);
}

/* Aumenta el tamaño del array cuando se necesita más espacio. */
void Heap::grow() {
    allocatedLength*=2;
    int* newElems = new int[allocatedLength];
    for (int i = 0; i < n; i++) {
        newElems[i] = T[i];
    }
    delete[] T;
    T = newElems;
}

/* Devuelve, pero no elimina, el primer elemento en la cola de prioridad. */
int Heap::peek() {
    if (isEmpty()) {
        cout<<"Cola esta vacia.";
    }
	return T[0];
}

/* Encola una nuevo elemento en la cola de prioridad. */
void Heap::enqueue(int value) {
    grow();
    T[size()] = value;
    bubbleUp(size());
    n++;
}

/* Devuelve y elimina el primer elemento de la cola de prioridades. */
int Heap::dequeue() {
    int v = T[0];

    T[0] = T[size()-1];

    bubbleDown(0); //bajo el último a su posicion
    n--;
    return(v);
}

/* Metodo para subir un nodo recién colocado y obtener un heap válido. */
void Heap::bubbleUp(int j ) { // j = childPos
/*
    int i_parent = ceil((j-1)/2);
    while(i_parent >= 0){
        if (T[i_parent] < T[j]){
            int v = T[i_parent];
            T[i_parent] = T[j];
            T[j] = v;
            j = i_parent;
            i_parent = ceil((j-1)/2);
        }
        else
            break;
    }
	*/
	//RECURSIVO
	int i_parent = ceil((j-1)/2);
	if (i_parent >= 0 && T[i_parent] < T[j]){
		int v = T[i_parent];
            T[i_parent] = T[j];
            T[j] = v;
         	bubbleUp(i_parent);	
	}		

		
}

/* Metodo para descender y obtener un heap válido. */
void Heap::bubbleDown(int fp) { // fp = parentPos
/*
    while(true){
        int i_l = 2*fp + 1;
        int i_r = 2*(fp+1);
        //i_mayor(i_child_l,i_child_l);
        if (i_l >= size() && i_r >= size())
            break;
        else{
            //averiguo el mayor
            int i_mayor;
            if (i_l >= size())
                i_mayor = i_r;
            else{
                if (i_r >= size())
                    i_mayor = i_l;
                else
                    i_mayor = (T[i_l] > T[i_r]) ? i_l : i_r;
            }

            if( T[fp] < T[i_mayor] ){
                int v = T[fp];
                T[fp] = T[i_mayor];
                T[i_mayor] = v;
                fp = i_mayor;
            }
            else
                break;
        }
    }
*/ 
	//RECURSIVO
	int i_l = 2*fp + 1;
    int i_r = 2*(fp+1);
	if (i_l < size() || i_r < size()){
		int i_mayor;
        if (i_l >= size())
            i_mayor = i_r;
        else{
            if (i_r >= size())
        	   i_mayor = i_l;
            else
               i_mayor = (T[i_l] > T[i_r]) ? i_l : i_r;
        }
		if( T[fp] < T[i_mayor] ){
            int v = T[fp];
            T[fp] = T[i_mayor];
            T[i_mayor] = v;
            fp = i_mayor;
			bubbleDown(fp);
        }		
	}	
}




