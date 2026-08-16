#include <stdint.h>

/*@
    predicate within_bounds(integer x, integer y) =
        1 <= x <= 10000 && 1 <= y <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bound: \forall integer x, y; 
        within_bounds(x, y) ==> product(x, y) <= 10000 * 10000;
*/

/*@
    requires within_bounds(a, b) && within_bounds(c, d);
    ensures \result == product(a, b) || \result == product(c, d);
    ensures \result >= product(a, b) && \result >= product(c, d);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d) {
    int64_t s1;
    int64_t s2;
    int64_t res;

    //@ assert within_bounds(a, b);
    //@ assert within_bounds(c, d);
    
    //@ assert product(a, b) <= 10000 * 10000;
    //@ assert product(c, d) <= 10000 * 10000;
    
    s1 = a * b;
    s2 = c * d;
    
    if (s1 > s2) {
        res = s1;
        //@ assert res == product(a, b);
    } else {
        res = s2;
        //@ assert res == product(c, d);
    }
    
    //@ assert res >= product(a, b);
    //@ assert res >= product(c, d);
    return res;
}
