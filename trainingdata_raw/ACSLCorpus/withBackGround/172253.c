#include <stdint.h>

/*@ predicate r_in_range(integer r) = 1 <= r && r <= 100; */

/*@
  requires r_in_range(r);
  ensures \result == 3 * r * r;
  assigns \nothing;
*/
int32_t func(uint32_t r) {
    int32_t pi;
    int32_t ans;
    
    pi = 3;
    
    //@ assert 3 * r * r <= 3 * 100 * 100;
    
    ans = pi * (int32_t)r * (int32_t)r;
    
    //@ assert ans == 3 * (int32_t)r * (int32_t)r;
    
    return ans;
}
