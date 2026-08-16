#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    lemma product_bound:
        \forall integer a, b; 
        valid_range(a) && valid_range(b) ==> 
        a * b >= 1 && a * b <= 100000000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == a * b || \result == c * d;
    ensures \result >= 1;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    // Variable declarations at scope top
    uint32_t sa;
    uint32_t sc;
    uint32_t ans;
    
    //@ assert a * b >= 1;
    sa = a * b;
    
    //@ assert c * d >= 1;
    sc = c * d;
    
    //@ assert sa == a * b && sc == c * d;
    
    if (sa > sc) {
        ans = sa;
    } else {
        ans = sc;
    }
    
    //@ assert ans == sa || ans == sc;
    return ans;
}
