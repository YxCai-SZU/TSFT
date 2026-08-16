#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bounds:
        \forall integer x, y;
        valid_range(x) && valid_range(y) ==> 
        0 < product(x, y) <= 10000 * 10000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= product(a, b);
    ensures \result >= product(c, d);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    // Variable declarations at scope top
    uint32_t s1;
    uint32_t s2;
    uint32_t result;

    //@ assert a > 0 && b > 0 && c > 0 && d > 0;
    //@ assert a <= 10000 && b <= 10000 && c <= 10000 && d <= 10000;
    
    //@ assert product(a, b) <= 10000 * 10000;
    //@ assert product(c, d) <= 10000 * 10000;

    s1 = a * b;
    s2 = c * d;

    if (s1 > s2) {
        //@ assert s1 >= product(a, b);
        //@ assert s1 >= product(c, d);
        result = s1;
    } else {
        //@ assert s2 >= product(a, b);
        //@ assert s2 >= product(c, d);
        result = s2;
    }

    return result;
}
