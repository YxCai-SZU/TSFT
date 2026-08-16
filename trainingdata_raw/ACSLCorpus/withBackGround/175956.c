#include <stdint.h>

/*@
    predicate is_valid_range(integer r) = 1 <= r <= 100;
    
    lemma square_bounds_lower:
        \forall integer r; is_valid_range(r) ==> r * r >= 1 * 1;
    
    lemma square_bounds_upper:
        \forall integer r; is_valid_range(r) ==> r * r <= 100 * 100;
    
    lemma square_identity:
        \forall integer r; is_valid_range(r) ==> r * r == r * r;
*/

/*@
    requires is_valid_range(r);
    ensures \result == r * r;
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    // Variable declarations at scope top
    int32_t ans;
    
    //@ assert is_valid_range(r);
    
    //@ assert r * r >= 1 * 1;
    //@ assert r * r <= 100 * 100;
    //@ assert r * r == r * r;
    
    ans = r * r;
    
    //@ assert ans == r * r;
    return ans;
}
