#include <iostream>
#include "heap.h"


using namespace std;

int main()
{
    Heap h;

    h.enqueue(18);
    h.enqueue(25);
    h.enqueue(41);
    h.enqueue(34);
    h.enqueue(14);
    h.enqueue(10);
    h.enqueue(52);
    h.enqueue(50);
    h.enqueue(48);

    cout << h.peek() << '\n';

    h.dequeue();

    cout << h.peek() << '\n';

    return 0;
}

