#include <stdint.h>

/*@ predicate valid_range(integer r) = 1 <= r <= 100; */

/*@ logic integer calculate_ans(integer r) = 6 * r; */

/*@ lemma ans_correct: 
      \forall integer r; valid_range(r) ==> calculate_ans(r) == 6 * r; */

/*@
  requires valid_range(r);
  ensures \result == calculate_ans(r);
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t ans;
    
    pi = 3;
    ans = 2 * r * pi;
    
    //@ assert ans == 6 * r;
    
    return ans;
}
