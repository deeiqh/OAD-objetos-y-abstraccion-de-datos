#include <iostream>
using namespace std;

int raiseToPower(int, int);
int main() {
    
    cout << raiseToPower(0,0);
    
    return 0;
}

int raiseToPower(int n, int k)
{
    if (k == 0) return 1;
    return n*raiseToPower(n, k-1);
}



