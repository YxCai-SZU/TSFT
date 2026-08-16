#include <stdint.h>

/*@ predicate is_valid_k(integer k) = 1 <= k && k <= 999; */

/*@
    lemma k_bounds:
        \forall integer k; is_valid_k(k) ==> 1 <= k && k <= 999;
*/

/*@
    requires is_valid_k(k);
    ensures \result >= 0 && \result <= 4;
    assigns \nothing;
*/
int32_t func(uint32_t k)
{
    int32_t result;
    uint32_t r;
    int32_t i;
    
    //@ assert is_valid_k(k);
    
    if (k % 2 == 0 || k % 5 == 0) {
        result = 0;
        //@ assert result >= 0 && result <= 4;
        return result;
    } else {
        r = 7;
        i = 1;
        
        /*@
            loop invariant 1 <= i && i <= 5;
            loop invariant 0 <= r && r <= 10000;
            loop invariant is_valid_k(k);
            loop assigns r, i;
            loop variant 5 - i;
        */
        while (i < 5) {
            //@ assert 1 <= i && i <= 5;
            r = (r * 10 + 7) % k;
            
            if (r == 0) {
                result = i;
                //@ assert result >= 0 && result <= 4;
                return result;
            }
            
            i = i + 1;
        }
    }
    
    result = 0;
    //@ assert result >= 0 && result <= 4;
    return result;
}
