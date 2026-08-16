#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (w) && (w) <= 100);
    ensures \result == ((n) * (w));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t w)
{
    // Variable declarations at scope top
    int32_t res;

    //@ assert (1 <= (n) && (n) <= 100 &&         1 <= (w) && (w) <= 100);
    //@ assert ((n) * (w)) <= 10000;
    
    res = (int32_t)n * (int32_t)w;
    
    //@ assert res == ((n) * (w));
    return res;
}
