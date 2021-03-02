#include "fraction.h"


/* Private functions */
Fraction __reduce(Fraction x);
int __get_gcd(int a, int b);


Fraction __reduce(Fraction x) {
    int gcd = __get_gcd(x.numerator, x.denominator);
    x.numerator /= gcd;
    x.denominator /= gcd;
    return x;
}

int __get_gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return __get_gcd(b, a % b);
}

Fraction get_fraction(int numerator, int denominator) {
    Fraction frac;
    frac.numerator = numerator;
    frac.denominator = denominator;
    frac = __reduce(frac);
    return frac;
}

Fraction init_fraction() {
    Fraction frac;
    frac.numerator = 0;
    frac.denominator = 1;
    frac = __reduce(frac);
    return frac;
}


Fraction add(Fraction a, Fraction b) {
    Fraction frac;
    frac.denominator = a.denominator * b.denominator;
    frac.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    frac = __reduce(frac);
    return frac;
}

Fraction subtract(Fraction a, Fraction b) {
    Fraction frac;
    frac.denominator = a.denominator * b.denominator;
    frac.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    frac = __reduce(frac);
    return frac;
}

Fraction multiply(Fraction a, Fraction b) {
    Fraction frac;
    frac.denominator = a.denominator * b.denominator;
    frac.numerator = a.numerator * b.numerator;
    frac = __reduce(frac);
    return frac;
}

Fraction divide(Fraction a, Fraction b) {
    Fraction frac;
    frac.denominator = a.denominator * b.numerator;
    frac.numerator = a.numerator * b.denominator;
    frac = __reduce(frac);
    return frac;
}
