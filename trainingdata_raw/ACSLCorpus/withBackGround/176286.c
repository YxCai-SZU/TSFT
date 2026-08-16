#include <stdint.h>

/*@
    predicate a_le_b_div_x(integer a, integer b, integer x) =
        a / x <= b / x;

    lemma a_le_b_div_x_lemma:
        \forall integer a, b, x;
            0 <= a <= b <= 1000000000000000000 &&
            1 <= x <= 1000000000000000000 ==>
            a / x <= b / x;
*/

/*@
    requires 0 <= a <= b <= 1000000000000000000;
    requires 1 <= x <= 1000000000000000000;
    ensures \result <= (b / x) - (a / x) + 1;
    ensures \result >= 0;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t x)
{
    // Variable declarations at scope top
    uint64_t ans;
    uint64_t tmp;

    //@ assert a <= b && a >= 0 && b <= 1000000000000000000;
    //@ assert x > 0 && x <= 1000000000000000000;
    
    //@ assert a_le_b_div_x(a, b, x);
    
    tmp = (a % x == 0) ? 1 : 0;
    ans = (b / x) - (a / x) + tmp;
    
    //@ assert ans >= 0;
    //@ assert ans <= (b / x) - (a / x) + 1;
    
    return ans;
}
