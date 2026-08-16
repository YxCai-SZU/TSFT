#include <stdbool.h>

/*@ requires 0 <= a && a < 10000;
    requires 0 <= b && b < 10000;
    requires 0 <= c && c < 10000;
    ensures \result == ((a * b) >= c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int product;
    
    //@ assert ((a) >= 0 && (a) < 10000 && (b) >= 0 && (b) < 10000 && (a * b) == (a) * (b) && (a * b) >= 0 && (a * b) < 10000 * 10000);
    product = a * b;
    
    //@ assert product == a * b;
    return product >= c;
}
