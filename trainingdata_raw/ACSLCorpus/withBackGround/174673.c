#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) = 0 <= a <= 100 && 0 <= b <= 100;
    
    logic integer compute_ans(integer a, integer p) = (a * 3 + p) / 2;
    
    lemma ans_bound:
        \forall integer a, p;
        valid_range(a, p) ==> compute_ans(a, p) <= 100 * 3 + 100;
*/

/*@
    requires valid_range(A, P);
    ensures \result == compute_ans(A, P);
    ensures \result <= 100 * 3 + 100;
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t P)
{
    uint32_t ans;
    
    //@ assert valid_range(A, P);
    ans = (A * 3 + P) / 2;
    
    //@ assert ans == compute_ans(A, P);
    //@ assert ans <= 100 * 3 + 100;
    
    return ans;
}
