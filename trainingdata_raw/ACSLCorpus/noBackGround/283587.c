#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    ensures \result == ((((a) * (b)) % 2) != 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b) {
    unsigned int product;
    bool is_odd = false;
    unsigned int abs_product;
    unsigned int remainder;
    
    //@ assert a * b <= 100000000;
    product = a * b;
    
    abs_product = product;
    
    if (product >= 2147483648) {
        abs_product = product - 2 * 2147483648;
    }
    
    remainder = abs_product;
    
    /*@
        loop invariant 0 <= remainder <= abs_product;
        loop invariant remainder <= a * b;
        loop invariant 1 <= a <= 10000;
        loop invariant 1 <= b <= 10000;
        loop invariant abs_product >= 0;
        loop invariant abs_product <= a * b;
        loop invariant remainder % 2 == abs_product % 2;
        loop invariant abs_product % 2 == (a * b) % 2;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2) {
        remainder -= 2;
    }
    
    if (remainder == 1) {
        is_odd = true;
    }
    
    //@ assert is_odd == ((a * b) % 2 != 0);
    return is_odd;
}
