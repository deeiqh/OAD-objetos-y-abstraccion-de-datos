#include <iostream>
#include "fraction.h"

Fraction::Fraction()
{
    num = 1;
    denom = 1;
}

// purpose: an overloaded constructor
Fraction::Fraction(int n, int d)
{
    num = n;
    denom = d;
    // reduce in case we were given an unreduced fraction
    reduce();
}

// getters for numerator and denominator
int Fraction::getNum() {
    return num;
}
int Fraction::getDenom() {
    return denom;
}

// purpose: to add another fraction
void Fraction::add(Fraction other) {
        // calculate the new numerator
        int new_num = num * other.denom + other.num * denom;

        // calculate the new denominator
        int new_denom = denom * other.denom;

        // replace our values with the new values
        num = new_num;
        denom = new_denom;

        // reduce the fraction
        reduce();
}

// purpose: to multiply another fraction
// with the result being stored in this fraction

void Fraction::mult(Fraction other)
{
    num *= other.num;
    denom *= other.denom;

    // reduce the fraction
    reduce();
}

// purpose: To return a decimal value of this fraction
float Fraction::decimal()
{
    return (float)num / denom;
}

// purpose: To reduce the fraction
void Fraction::reduce() {
    // reduce the fraction to lowest terms find the greatest common divisor
    int frac_gcd = gcd(num,denom);

    // reduce by dividing num and denom by the gcd
    num = num / frac_gcd;
    denom = denom / frac_gcd;
}

// purpose: To recursively find the greatest common divisor of the two integers
int Fraction::gcd(int u, int v) {
    if (v != 0) {
        return gcd(v,u%v);
    }
    else {
        return u;
    }
}

// purpose: To overload the << operator
ostream& operator<<(ostream& out, Fraction &frac) {
    out << frac.num << "/" << frac.denom;
    return out;
}

void Fraction::reciprocal()
{
    if (num != 0){
        int num_ = num;
        num = denom;
        denom = num_;
    }
}

void Fraction::divide(Fraction f)
{
    num *= f.denom;
    denom *= f.num;
    
    reduce();
}

bool Fraction::operator==(Fraction &f)
{
    return this->getNum()*f.getDenom() == this->getDenom()*f.getNum();
}

bool Fraction::operator!=(Fraction &f)
{
    return this->getNum()*f.getDenom() != this->getDenom()*f.getNum();
}

bool Fraction::operator<(Fraction &f)
{
    return this->getNum()*f.getDenom() < this->getDenom()*f.getNum();
}

bool Fraction::operator<=(Fraction &f)
{
    return this->getNum()*f.getDenom() <= this->getDenom()*f.getNum();
}

bool Fraction::operator>(Fraction &f)
{
    return this->getNum()*f.getDenom() > this->getDenom()*f.getNum();
}

bool Fraction::operator>=(Fraction &f)
{
    return this->getNum()*f.getDenom() >= this->getDenom()*f.getNum();
}