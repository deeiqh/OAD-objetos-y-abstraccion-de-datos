#ifndef PQueue_Heap_Included
#define PQueue_Heap_Included
using namespace std;

class Heap {
public:
	/* Construye una nueva cola de prioridad vacía respaldada por un heap binario. */
	Heap();
	/* Limpia toda la memoria asignada por esta cola de prioridad. */
	~Heap();
	/* Retorna el número de elementos de la cola de prioridad. */
	int size();
	/* Retorna si la cola de prioridad está o no vacía. */
	bool isEmpty();
	/* Encola una nuevo elemento en la cola de prioridad. */
	void enqueue(int value);
	/* Devuelve, pero no elimina, el primer elemento en la cola de prioridad.*/
	int peek();
	/* Devuelve y elimina el primer elemento de la cola de prioridades. */
	int dequeue();

private:
    /* Almacena la longitud del array que contiene el heap.*/
    int allocatedLength;

    /* Almacena el número real de elementos en el heap.*/
    int n;

    /* Array que representa el heap.*/
    int* T;

    /* Aumenta el tamaño del array cuando se necesita más espacio.*/
    void grow();

    /* Metodo para subir un nodo recién colocado para obtener un heap válido. */
    void bubbleUp(int childPos);

    /* Metodo para descender para obtener un heap válido. */
    void bubbleDown(int parentPos);
};

#endif
