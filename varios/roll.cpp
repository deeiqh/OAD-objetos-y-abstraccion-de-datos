#include <iostream>
#include <stack>

using namespace std;

void imprimir_pila(stack<char>);
void roll(stack<char>*, int, int);

int main() {

    stack<char> pila;
    for(char c ='A'; c != 'E'; c++)
        pila.push(c);    
    imprimir_pila(pila);
    
    int n = 2, k = 4;
    roll(&pila, n, k);
    imprimir_pila(pila);
    
    return 0;

}

void imprimir_pila(stack<char> pila)
{
    while(!pila.empty()){
        cout << pila.top() << '\n';
        pila.pop();
    }
    cout << '\n';
}

void exch(stack<char>* pila) // intercambia los 2 tops de la pila
{
    char t1, t2;
    
    t1 = pila->top();
    pila->pop();
    t2 = pila->top();
    pila->pop();
    
    pila->push(t1);
    pila->push(t2);
    
}

void roll(stack<char>* pila, int n, int k)
{   //el proceso se repite k-1 veces: intercambio los tops, en una nueva pila coloco 
    //el top (se van apilando de forma rotada) luego desapilo para colocarlos en la pila original
    //y con la forma de rotacion pedida
    stack<char> pila_temp;
    for(int j = 0; j != k; j++){
        for(int i = 0; i != n-1; i++){
            exch(pila);
            pila_temp.push(pila->top());
            pila->pop();
        }
        while(!pila_temp.empty()){
            pila->push( pila_temp.top());
            pila_temp.pop();
        }
    }
}