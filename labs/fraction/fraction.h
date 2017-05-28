#include<iostream>
using namespace std;

class Fraction {
public:
    Fraction();
    Fraction(int num,int denom);

    void add(Fraction f);
    void mult(Fraction f);
    float decimal();
    int getNum();
    int getDenom();
    friend ostream& operator<<(ostream& out, Fraction &frac);
    void reciprocal();
    void divide(Fraction f);
    bool operator==(Fraction &f);
    bool operator!=(Fraction &f);
    bool operator<(Fraction &f);
    bool operator<=(Fraction &f);
    bool operator>(Fraction &f);
    bool operator>=(Fraction &f);
private:
    int num;   // the numerator
    int denom; // the denominator
    void reduce(); // reduce the fraction to lowest terms
    int gcd(int u, int v);
};