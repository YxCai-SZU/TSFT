#include <stdint.h>

/*@ predicate valid_time(integer h, integer m) =
      0 <= h && h <= 23 && 0 <= m && m <= 59;
*/

/*@ predicate time_order(integer h1, integer m1, integer h2, integer m2) =
      h1 <= h2 && (h1 == h2 ==> m1 <= m2);
*/

/*@ logic integer minutes(integer h, integer m) = h * 60 + m; */

/*@ lemma ans_lower_bound:
      \forall integer h1, m1, h2, m2, k, start, end, ans;
      valid_time(h1, m1) && valid_time(h2, m2) &&
      0 <= k && k <= 100000 &&
      time_order(h1, m1, h2, m2) &&
      start == minutes(h1, m1) &&
      end == minutes(h2, m2) &&
      ans == (end - start - k > 0 ? end - start - k : 0) ==>
      ans >= -k;
*/

/*@ lemma ans_upper_bound:
      \forall integer h1, m1, h2, m2, k, start, end, ans;
      valid_time(h1, m1) && valid_time(h2, m2) &&
      0 <= k && k <= 100000 &&
      time_order(h1, m1, h2, m2) &&
      start == minutes(h1, m1) &&
      end == minutes(h2, m2) &&
      ans == (end - start - k > 0 ? end - start - k : 0) ==>
      ans <= 60 * (h2 - h1) + m2 - m1;
*/

/*@
  requires valid_time(h1, m1) && valid_time(h2, m2);
  requires 0 <= k && k <= 100000;
  requires time_order(h1, m1, h2, m2);
  ensures \result >= -k;
  ensures \result <= 60 * (h2 - h1) + m2 - m1;
*/
int64_t func(int64_t h1, int64_t m1, int64_t h2, int64_t m2, int64_t k)
{
    int64_t start_minutes;
    int64_t end_minutes;
    int64_t ans;
    
    start_minutes = h1 * 60 + m1;
    end_minutes = h2 * 60 + m2;
    
    //@ assert start_minutes == minutes(h1, m1);
    //@ assert end_minutes == minutes(h2, m2);
    
    if (end_minutes - start_minutes - k > 0) {
        ans = end_minutes - start_minutes - k;
    } else {
        ans = 0;
    }
    
    //@ assert ans == (end_minutes - start_minutes - k > 0 ? end_minutes - start_minutes - k : 0);
    
    //@ assert ans >= -k;
    //@ assert ans <= 60 * (h2 - h1) + m2 - m1;
    
    return ans;
}
