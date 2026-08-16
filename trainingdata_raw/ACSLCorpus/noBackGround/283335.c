#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= 1;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d) {
    // Declare all variables at the top
    uint64_t res;
    uint64_t ab_product;
    uint64_t cd_product;
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    //@ assert ((a) * (b)) >= 1;
    //@ assert ((c) * (d)) >= 1;
    
    //@ assert ((a) * (b)) <= 100000000;
    //@ assert ((c) * (d)) <= 100000000;
    
    ab_product = a * b;
    cd_product = c * d;
    
    if (ab_product < cd_product) {
        res = cd_product;
        //@ assert res == ((c) * (d));
    } else {
        res = ab_product;
        //@ assert res == ((a) * (b));
    }
    
    //@ assert res >= 1;
    return res;
}
