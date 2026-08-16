#include <stdint.h>

/*@
    requires (0 <= (a) <= 100);
    requires (0 <= (b) <= 100);
    requires (0 <= (c) <= 100);
    requires (0 <= (d) <= 100);
    ensures \result == a * c || \result == a * d || 
            \result == b * c || \result == b * d;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t max_ab;
    uint32_t max_cd;
    uint32_t result;

    //@ assert (0 <= (a) <= 100);
    //@ assert (0 <= (b) <= 100);
    //@ assert (0 <= (c) <= 100);
    //@ assert (0 <= (d) <= 100);

    max_ab = a > b ? a : b;
    //@ assert (0 <= (max_ab) <= 100);

    max_cd = c > d ? c : d;
    //@ assert (0 <= (max_cd) <= 100);

    //@ assert max_ab * max_cd <= 10000;

    result = max_ab * max_cd;
    
    //@ assert result == a * c || result == a * d || result == b * c || result == b * d;
    return result;
}
