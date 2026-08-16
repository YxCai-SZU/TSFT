#include <stdint.h>

/*@
    predicate bounds(integer v) = 1 <= v <= 10000;

    logic integer min(integer x, integer y) = x < y ? x : y;

    lemma sum_bounds:
        \forall integer a, b;
            bounds(a) && bounds(b) ==> a + b <= 20000;

    lemma min_bounds:
        \forall integer a, b;
            bounds(a) && bounds(b) ==> min(a, b) <= 10000;
*/

/*@
    requires bounds(a) && bounds(b) && bounds(c) && bounds(d);
    ensures \result == min(a, b) + min(c, d);
    ensures \result <= a + c;
    ensures \result <= b + d;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    //@ assert bounds(a) && bounds(b) && bounds(c) && bounds(d);
    
    //@ assert a + c <= 20000;
    //@ assert b + d <= 20000;
    
    //@ assert min(a, b) <= 10000;
    //@ assert min(c, d) <= 10000;
    
    uint32_t result;
    uint32_t min_ab;
    uint32_t min_cd;
    
    min_ab = a < b ? a : b;
    min_cd = c < d ? c : d;
    result = min_ab + min_cd;
    
    //@ assert result == min(a, b) + min(c, d);
    //@ assert result <= a + c;
    //@ assert result <= b + d;
    
    return result;
}
