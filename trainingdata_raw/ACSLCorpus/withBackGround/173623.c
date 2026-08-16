#include <stdint.h>

/*@ predicate valid_params(integer x, integer y, integer z) =
       1 <= x && 1 <= y && 1 <= z &&
       x <= 100000 && y <= 100000 && z <= 100000 &&
       y + z <= x;
    @
    @ logic integer compute_numerator(integer x, integer z) = x - z;
    @
    @ logic integer compute_denominator(integer y, integer z) = y + z;
    @
    @ lemma ans_bounds: \forall integer x, integer y, integer z, integer ans;
       valid_params(x, y, z) && ans >= 0 && compute_numerator(x, z) >= 0 && 
       ans <= x - compute_numerator(x, z) ==> ans <= x;
    @
    @ lemma numerator_bounds: \forall integer x, integer y, integer z;
       valid_params(x, y, z) ==> 
       compute_numerator(x, z) >= 0 && compute_numerator(x, z) <= x;
    @
    @ lemma denominator_positive: \forall integer x, integer y, integer z;
       valid_params(x, y, z) ==> compute_denominator(y, z) >= 0;
    @*/

/*@ requires valid_params(x, y, z);
    @ assigns \nothing;
    @ ensures \result >= 0 && \result <= x;
    @*/
int64_t func(int64_t x, int64_t y, int64_t z) {
    int64_t ans;
    int64_t numerator;
    int64_t denominator;
    
    ans = 0;
    numerator = x - z;
    denominator = y + z;
    
    /*@ loop invariant valid_params(x, y, z);
      @ loop invariant numerator >= 0 && numerator <= x;
      @ loop invariant ans >= 0 && ans <= x;
      @ loop invariant ans <= x - numerator;
      @ loop assigns numerator, ans;
      @ loop variant numerator;
      @*/
    while (numerator >= denominator) {
        //@ assert numerator >= 0;
        
        numerator -= denominator;
        ans += 1;
    }
    
    return ans;
}
