#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer area(integer r) = 3 * r * r;
    
    lemma area_non_negative: \forall integer r; valid_range(r) ==> area(r) >= 0;
    lemma area_bound: \forall integer r; valid_range(r) ==> 3 * r <= 300;
    lemma area_bound2: \forall integer r; valid_range(r) ==> 3 * r * r <= 30000;
*/

/*@
    requires valid_range(r);
    ensures \result == area(r);
    ensures \result >= 0;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t ans;
    
    pi = 3;
    
    //@ assert 3 * r <= 300;
    
    //@ assert 3 * r * r <= 30000;
    
    ans = pi * r * r;
    
    //@ assert ans == 3 * r * r;
    
    return ans;
}
