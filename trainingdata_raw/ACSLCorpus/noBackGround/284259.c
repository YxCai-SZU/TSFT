#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b));
    ensures \result >= ((c) * (d));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t s1;
    uint32_t s2;
    uint32_t res;
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    //@ assert ((a) * (b)) <= 100000000;
    //@ assert ((c) * (d)) <= 100000000;
    
    s1 = a * b;
    s2 = c * d;
    
    if (s1 >= s2) {
        res = s1;
    } else {
        res = s2;
    }
    
    //@ assert res == ((a) * (b)) || res == ((c) * (d));
    //@ assert res >= ((a) * (b));
    //@ assert res >= ((c) * (d));
    
    return res;
}
