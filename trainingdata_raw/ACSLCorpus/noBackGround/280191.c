#include <stdbool.h>

/*@ requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int x1;
    unsigned int x2;
    unsigned int x3;
    bool result;

    x1 = a;
    x2 = b;
    x3 = c;

    //@ assert x1 == a && x2 == b && x3 == c;

    result = (x1 < x2 && x2 < x3);
    return result;
}
