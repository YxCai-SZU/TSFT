#include <stdint.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 123;
    
    logic integer min(integer x, integer y) = x < y ? x : y;
    
    lemma multiplication_bounds:
        \forall integer e, t;
        in_range(e) && in_range(t) ==>
        (e + 1) * t <= 124 * 123;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d) && in_range(e);
    ensures \result >= 0 && \result <= 50000;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d, uint32_t e)
{
    uint32_t m;
    uint32_t n;
    uint32_t t;
    uint32_t o;
    int32_t result;
    
    //@ assert in_range(a) && in_range(b) && in_range(c) && in_range(d) && in_range(e);
    
    m = a < b ? a : b;
    //@ assert in_range(m);
    
    n = c < d ? c : d;
    //@ assert in_range(n);
    
    t = m < n ? m : n;
    //@ assert in_range(t);
    
    //@ assert e + 1 <= 124;
    //@ assert (e + 1) * t <= 124 * 123;
    
    o = (e + 1) * t;
    
    if (o > 123)
    {
        result = 50000;
        //@ assert result >= 0 && result <= 50000;
        return result;
    }
    
    result = (int32_t)o;
    //@ assert result >= 0 && result <= 50000;
    return result;
}
