#include <stdint.h>

/*@
    predicate l_in_range(integer l) = 1 <= l <= 1000;

    logic integer func_spec(integer l) =
        (l / 3) * (l / 3) * (l - l / 3 - l / 3) * 2;

    lemma div3_bound: \forall integer l; l_in_range(l) ==> l / 3 <= 333;
    lemma sub_bound: \forall integer l; l_in_range(l) ==> l - l / 3 - l / 3 <= 1000;
    lemma mul_bound1: \forall integer l; l_in_range(l) ==> (l / 3) * (l / 3) <= 333 * 333;
    lemma mul_bound2: \forall integer l; l_in_range(l) ==> 
        (l / 3) * (l / 3) * (l - l / 3 - l / 3) * 2 <= 333 * 333 * 1000 * 2;
*/

/*@
    requires l_in_range(l);
    ensures \result == func_spec(l);
    assigns \nothing;
*/
int64_t func(int64_t l)
{
    uint64_t l_unsigned;
    uint64_t ans;
    
    //@ assert l_in_range(l);
    
    if (l < 0) {
        l_unsigned = (uint64_t)(-l);
    } else {
        l_unsigned = (uint64_t)l;
    }
    
    //@ assert l_unsigned / 3 <= 333;
    //@ assert l_unsigned - l_unsigned / 3 - l_unsigned / 3 <= 1000;
    //@ assert (l_unsigned / 3) * (l_unsigned / 3) <= 333 * 333;
    
    ans = (l_unsigned / 3) * (l_unsigned / 3) * (l_unsigned - l_unsigned / 3 - l_unsigned / 3) * 2;
    
    //@ assert ans == func_spec(l_unsigned);
    
    if (l < 0) {
        return -(int64_t)ans;
    } else {
        return (int64_t)ans;
    }
}
