#include <iostream>
#include "fraction.h"

using namespace std;

int main() {

    Fraction f(4,1);
    Fraction g(8,1);
    
    cout << (f<g) << '\n';
    
    f.reciprocal();
    cout << f << '\n';
    
    f.reciprocal(); // f original
    f.divide(g);
    cout << f;
    
    return 0;
}