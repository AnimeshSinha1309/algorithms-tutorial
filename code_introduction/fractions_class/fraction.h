#ifndef __LIB_FRACTIONS_H
#define __LIB_FRACTIONS_H

struct Fraction {
  int numerator;
  int denominator;
};
typedef struct Fraction Fraction;
Fraction add(Fraction, Fraction);
Fraction subtract(Fraction, Fraction);
Fraction multiply(Fraction, Fraction);
Fraction divide(Fraction, Fraction);
Fraction get_fraction(int, int);
Fraction init_fraction();

#endif // __LIB_FRACTIONS_H
