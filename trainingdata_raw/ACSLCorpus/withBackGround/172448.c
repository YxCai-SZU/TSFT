#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b, integer c) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 100;

    logic integer safe_div(integer b, integer a) = b / a;

    lemma div_bound: \forall integer a, b; 1 <= a <= 100 && 1 <= b <= 100 ==> safe_div(b, a) <= 100;
*/

/*@
    requires valid_inputs(a, b, c);
    ensures \result <= c;
    ensures \result <= b / a;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    // Variable declarations at scope top
    uint32_t ans;
    uint32_t div_result;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    
    //@ assert b / a <= 100;
    //@ assert c <= 100;
    
    div_result = b / a;
    
    if (c < div_result) {
        ans = c;
    } else {
        ans = div_result;
    }
    
    //@ assert ans <= c;
    //@ assert ans <= b / a;
    
    return ans;
}
