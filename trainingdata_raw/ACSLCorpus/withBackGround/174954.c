#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b, integer c) =
        0 <= a <= 1000000000000000000 &&
        0 <= b <= 1000000000000000000 &&
        0 <= c <= 1000000000000000000 &&
        a + b + 1 <= c;
*/

/*@
    logic integer min_val(integer a, integer b, integer c) =
        (c < a + b + 1) ? c : (a + b + 1);
*/

/*@
    lemma min_val_bounds:
        \forall integer a, b, c;
        valid_inputs(a, b, c) ==> a + b + 1 <= min_val(a, b, c) <= c;
*/

/*@
    lemma ans_bounds:
        \forall integer a, b, c;
        valid_inputs(a, b, c) ==>
        0 <= b - (min_val(a, b, c) - a - 1) <= b;
*/

/*@
    requires valid_inputs(a, b, c);
    ensures \result >= 0 && \result <= b;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    //@ assert a + b + 1 <= c;
    //@ assert a + b + 1 <= 9223372036854775807;
    //@ assert b >= 0;
    //@ assert b <= 9223372036854775807;
    
    int64_t min_val;
    int64_t ans;
    
    //@ ghost int64_t original_a = a;
    //@ ghost int64_t original_b = b;
    //@ ghost int64_t original_c = c;
    
    if (c < a + b + 1) {
        min_val = c;
    } else {
        min_val = a + b + 1;
    }
    
    //@ assert min_val == min_val(original_a, original_b, original_c);
    //@ assert a + b + 1 <= min_val <= c;
    
    ans = b - (min_val - a - 1);
    
    //@ assert ans >= 0;
    //@ assert ans <= b;
    //@ assert a + b + 1 <= c;
    
    return ans;
}
