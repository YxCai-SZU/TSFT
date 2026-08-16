#include <stdint.h>

/*@
    predicate is_zero(integer x) = x == 0;
    predicate is_one(integer x) = x == 1;
    
    logic integer compute_result(integer x) = 1 - x;
    
    lemma result_zero:
        \forall integer x; is_zero(x) ==> compute_result(x) == 1;
    
    lemma result_one:
        \forall integer x; is_one(x) ==> compute_result(x) == 0;
*/

/*@
    requires 0 <= x <= 1;
    ensures (x == 0 ==> \result == 1) && (x == 1 ==> \result == 0);
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    int32_t res;
    
    //@ ghost
    //@ assert x == 0 || x == 1;
    
    //@ assert x == 0 ==> 1 - (int32_t)x == 1;
    //@ assert x == 1 ==> 1 - (int32_t)x == 0;
    
    res = 1 - (int32_t)x;
    
    //@ assert (x == 0 ==> res == 1) && (x == 1 ==> res == 0);
    
    return res;
}
