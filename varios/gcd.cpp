#include <iostream>
using namespace std;

int gcd(int, int);

int main() {

    cout << gcd(1, 81);	
    
    return 0;
}

int gcd(int x, int y)
{
    if (x % y == 0) return y;
    else
    {
        return gcd(y, x%y);
    }
}