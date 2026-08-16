#include <stdint.h>

/*@
    predicate r_in_range(integer r) = 1 <= r <= 100;
    
    logic integer func_spec(integer r) = 3 * r * r;
    
    lemma func_bound: \forall integer r; r_in_range(r) ==> 3 * r * r <= 30000;
*/

/*@
    requires r_in_range(r);
    ensures \result == func_spec(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t result;
    
    //@ assert 1 <= r <= 100;
    //@ assert 1 * r <= 100 * r;
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r <= 30000;
    
    result = 3 * r * r;
    return result;
}
