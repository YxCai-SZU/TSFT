#include <stdint.h>

/*@ predicate non_negative(integer x) = x >= 0; */
/*@ predicate bounded_50(integer x) = 0 <= x <= 50; */
/*@ predicate result_range(integer x) = 0 <= x <= 2; */

/*@ logic integer sum_b_c(integer b, integer c) = b + c; */

/*@ lemma sum_b_c_bounded: 
      \forall integer b, c; 
      bounded_50(b) && bounded_50(c) ==> 
      non_negative(sum_b_c(b, c)) && sum_b_c(b, c) <= 100; */

/*@ requires bounded_50(a) && bounded_50(b) && bounded_50(c); 
    ensures result_range(\result); 
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t ans;
    
    //@ assert non_negative(a) && non_negative(b) && non_negative(c);
    
    if (c <= a + b) {
        //@ assert sum_b_c(b, c) <= 100;
        //@ assert non_negative(sum_b_c(b, c));
        
        if (b + c > a) {
            ans = 1;
        } else {
            ans = 0;
        }
    } else {
        ans = 2;
    }
    
    //@ assert result_range(ans);
    return ans;
}
