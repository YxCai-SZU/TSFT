#include <stdint.h>

/*@
    predicate radius_in_range(integer r) = 1 <= r && r <= 100;
    
    logic integer area(integer r) = 3 * r * r;
    
    lemma area_bound: \forall integer r; radius_in_range(r) ==> area(r) <= 3 * 100 * 100;
*/

/*@
    requires radius_in_range(r);
    ensures \result == area(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi;
    int64_t result;
    
    //@ assert radius_in_range(r);
    
    pi = 3;
    
    //@ assert area(r) <= 3 * 100 * 100;
    
    result = pi * r * r;
    
    //@ assert result == area(r);
    
    return result;
}
