#include <stdint.h>

/*@
    predicate is_one(integer x) = x == 1;
    predicate is_zero(integer x) = x == 0;

    logic integer complement(integer x) = 
        (x == 1) ? 0 : 1;

    lemma complement_property:
        \forall integer x; 
            (0 <= x <= 1) ==> 
            (is_one(x) ==> complement(x) == 0) && 
            (is_zero(x) ==> complement(x) == 1);
*/

/*@
    requires 0 <= x <= 1;
    ensures (x == 1 ==> \result == 0);
    ensures (x == 0 ==> \result == 1);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t ans;
    //@ assert 0 <= x <= 1;
    
    if (x == 1) {
        ans = 0;
    } else {
        ans = 1;
    }
    
    //@ assert (x == 1 ==> ans == 0);
    //@ assert (x == 0 ==> ans == 1);
    return ans;
}
