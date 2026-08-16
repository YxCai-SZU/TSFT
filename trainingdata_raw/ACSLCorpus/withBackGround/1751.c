#include <stdint.h>

/*@
    predicate is_valid_input(integer x) = 0 <= x && x <= 1;
    
    logic integer compute_ans(integer x) = 1 - x;
    
    lemma ans_correct: 
        \forall integer x; is_valid_input(x) ==> compute_ans(x) == 1 - x;
*/

/*@
    requires is_valid_input(x);
    ensures \result == compute_ans(x);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t ans;
    
    //@ assert is_valid_input(x);
    
    ans = 1 - x;
    
    //@ assert ans == compute_ans(x);
    
    return ans;
}
