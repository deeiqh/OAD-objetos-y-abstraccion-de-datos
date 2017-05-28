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
}

/* Prints the contents of a linked list recursively. */
void printListRec(Celda* list) {
    /* Base Case: Empty list, nothing to print! */
    if (list == NULL) return;

    /* Recursive Step: Print the first element, then the remaining ones. */
    cout << list->valor << endl;
    printListRec(list->next);
}

int main() {
    Celda* lista = readListRec();
    printListRec(lista);

    return 0;
}
