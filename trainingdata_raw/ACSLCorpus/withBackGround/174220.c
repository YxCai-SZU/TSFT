#include <stdint.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;

    // Logical computation for the operation
    logic integer compute_result(integer a, integer b) = 
        (a - b * 2) > 0 ? (a - b * 2) : 0;

    // Proof lemma for arithmetic bounds
    lemma b2_bound: \forall integer b; valid_range(b) ==> b * 2 <= 200;
    lemma diff_bound: \forall integer a, integer b; 
        valid_range(a) && valid_range(b) ==> a - b * 2 <= 100;
    lemma result_non_negative: \forall integer a, integer b; 
        valid_range(a) && valid_range(b) ==> compute_result(a, b) >= 0;
    lemma result_upper_bound: \forall integer a, integer b; 
        valid_range(a) && valid_range(b) ==> compute_result(a, b) <= a;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    ensures \result >= 0;
    ensures \result <= a;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b)
{
    int32_t ans;
    
    //@ assert b * 2 <= 200;
    //@ assert a - b * 2 <= 100;
    
    ans = a - b * 2;
    
    if (ans > 0) {
        //@ assert ans <= a;
        return ans;
    } else {
        //@ assert 0 <= a;
        return 0;
    }
}
