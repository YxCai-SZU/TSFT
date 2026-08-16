#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer min(integer x, integer y) = (x < y) ? x : y;
    
    lemma ans_correct:
        \forall integer a, b, c, d, min1, min2, ans;
        valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) &&
        min1 == min(a, b) && min2 == min(c, d) && ans == min1 + min2 ==>
        ans == a + c || ans == b + d || ans == a + d || ans == b + c;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == a + c || \result == b + d || \result == a + d || \result == b + c;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    uint32_t min1;
    uint32_t min2;
    uint32_t ans;
    
    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    
    if (a < b) {
        min1 = a;
    } else {
        min1 = b;
    }
    //@ assert min1 == a || min1 == b;
    
    if (c < d) {
        min2 = c;
    } else {
        min2 = d;
    }
    //@ assert min2 == c || min2 == d;
    
    ans = min1 + min2;
    //@ assert ans == min1 + min2;
    
    //@ assert ans == a + c || ans == b + d || ans == a + d || ans == b + c;
    
    return ans;
}
