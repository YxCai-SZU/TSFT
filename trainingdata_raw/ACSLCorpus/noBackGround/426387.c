#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && 
             (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= 1;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d)
{
    // Declare all variables at the top
    uint64_t ab;
    uint64_t cd;
    uint64_t res;
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert ((a) * (b)) <= 100000000;
    
    ab = a * b;
    
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    //@ assert ((c) * (d)) <= 100000000;
    
    cd = c * d;
    
    //@ assert ab == ((a) * (b));
    //@ assert cd == ((c) * (d));
    
    if (ab > cd) {
        res = ab;
    } else {
        res = cd;
    }
    
    //@ assert res == ((a) * (b)) || res == ((c) * (d));
    //@ assert res >= 1;
    
    return res;
}
