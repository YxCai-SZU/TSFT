#include <stdint.h>
/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b));
    ensures \result >= ((c) * (d));
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d) {
    uint64_t product_ab;
    uint64_t product_cd;
    uint64_t result;

    //@ assert a <= 10000 && b <= 10000;
    //@ assert c <= 10000 && d <= 10000;
    
    //@ assert ((a) * (b)) <= 100000000;
    product_ab = a * b;
    
    //@ assert ((c) * (d)) <= 100000000;
    product_cd = c * d;
    
    if (product_ab > product_cd) {
        //@ assert product_ab >= ((a) * (b));
        //@ assert product_ab >= ((c) * (d));
        result = product_ab;
    } else {
        //@ assert product_cd >= ((a) * (b));
        //@ assert product_cd >= ((c) * (d));
        result = product_cd;
    }
    
    return result;
}
