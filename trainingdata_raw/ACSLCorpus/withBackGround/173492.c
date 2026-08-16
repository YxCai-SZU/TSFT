#include <stdint.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;

    logic integer div_mul(integer c, integer b, integer a) = (c / b) * a;
    logic integer div_mul2(integer a, integer d, integer c) = (a / d) * c;
    logic integer final_result(integer a, integer b, integer c, integer d) = 
        div_mul(c, b, a) - div_mul2(a, d, c);

    lemma div_bound1: \forall integer a, b, c, d; 
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==> 
        c / b <= 10000;
    lemma mul_bound1: \forall integer a, b, c, d; 
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==> 
        (c / b) * a <= 10000 * 10000;
    lemma div_bound2: \forall integer a, b, c, d; 
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==> 
        a / d <= 10000;
    lemma mul_bound2: \forall integer a, b, c, d; 
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) ==> 
        (a / d) * c <= 10000 * 10000;
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == final_result(a, b, c, d);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    uint32_t x;
    uint32_t y;
    int32_t result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);
    
    //@ assert c / b <= 10000;
    x = c / b * a;
    
    //@ assert a / d <= 10000;
    y = a / d * c;
    
    result = (int32_t)x - (int32_t)y;
    
    //@ assert result == final_result(a, b, c, d);
    return result;
}
