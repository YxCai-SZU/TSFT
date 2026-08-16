#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 10000;
    predicate b_in_range(integer b) = 1 <= b <= 10000;
    predicate c_in_range(integer c) = 1 <= c <= 10000;
    predicate d_in_range(integer d) = 1 <= d <= 10000;
    
    logic integer product(integer x, integer y) = x * y;
    
    lemma product_bound_a_b:
        \forall integer a, b; a_in_range(a) && b_in_range(b) ==> 
        product(a, b) <= 10000 * 10000;
    
    lemma product_bound_c_d:
        \forall integer c, d; c_in_range(c) && d_in_range(d) ==> 
        product(c, d) <= 10000 * 10000;
    
    lemma product_self_geq_a_b:
        \forall integer a, b; a_in_range(a) && b_in_range(b) ==> 
        product(a, b) >= product(a, b);
    
    lemma product_self_geq_c_d:
        \forall integer c, d; c_in_range(c) && d_in_range(d) ==> 
        product(c, d) >= product(c, d);
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == a * b || \result == c * d;
    ensures \result >= a * b;
    ensures \result >= c * d;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    uint32_t sa;
    uint32_t sc;
    uint32_t res;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert c_in_range(c);
    //@ assert d_in_range(d);
    
    sa = a * b;
    sc = c * d;
    
    if (sa > sc) {
        res = sa;
    } else {
        res = sc;
    }
    
    //@ assert res == sa || res == sc;
    
    return res;
}
