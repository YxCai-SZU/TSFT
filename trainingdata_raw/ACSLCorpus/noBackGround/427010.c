#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= ((a) * (b)) && \result >= ((c) * (d));
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d)
{
    // Variable declarations at scope top
    uint64_t sa;
    uint64_t sc;
    uint64_t result;
    
    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    //@ assert ((a) * (b)) <= 18446744073709551615;
    sa = a * b;
    
    //@ assert (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    //@ assert ((c) * (d)) <= 18446744073709551615;
    sc = c * d;
    
    if (sa > sc)
    {
        result = sa;
        //@ assert result == ((a) * (b));
    }
    else
    {
        result = sc;
        //@ assert result == ((c) * (d));
    }
    
    //@ assert result >= ((a) * (b)) && result >= ((c) * (d));
    return result;
}
