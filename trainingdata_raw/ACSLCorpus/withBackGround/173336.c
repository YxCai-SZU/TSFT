#include <stdint.h>

/*@ predicate is_valid_range(integer r) = 1 <= r && r <= 100; */

/*@ lemma r_square_bound: 
      \forall integer r; is_valid_range(r) ==> r * r <= 10000; */

/*@ lemma triple_square_bound: 
      \forall integer r; is_valid_range(r) ==> 3 * (r * r) <= 30000; */

/*@ requires is_valid_range(r);
    requires r == (int64_t)r;
    ensures \result == 3 * (r * r);
    assigns \nothing;
 */
int64_t func(int64_t r)
{
    int64_t ans;
    
    //@ assert 1 <= r <= 100;
    //@ assert r * r <= 10000;
    //@ assert 3 * (r * r) <= 30000;
    
    ans = 3 * (r * r);
    
    //@ assert ans == 3 * (r * r);
    return ans;
}
