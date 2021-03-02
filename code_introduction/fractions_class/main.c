#include <stdio.h>
#include "fraction.h"

int main() {
    Fraction a = get_fraction(2, 3);
    Fraction b = get_fraction(5, 6);
    Fraction c = multiply(a, b);
    printf("%d %d\n", c.numerator, c.denominator);
}
