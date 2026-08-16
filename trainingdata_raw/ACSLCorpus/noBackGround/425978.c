#include <stdint.h>

/*@
  requires (0 <= (h1) && (h1) <= 23 &&
      0 <= (m1) && (m1) <= 59) && (0 <= (h2) && (h2) <= 23 &&
      0 <= (m2) && (m2) <= 59) && ((h1) <= (h2) &&
      (((h1) == (h2) && (m1) <= (m2)) || ((h1) < (h2)))) && k >= 0;
  ensures \result == 60 * (h2 - h1) + m2 - m1 - k;
*/
int64_t func(int64_t h1, int64_t m1, int64_t h2, int64_t m2, int64_t k)
{
    int64_t start_minutes;
    int64_t end_minutes;
    int64_t ans;
    
    //@ assert (60 * (h2) + (m2)) >= (60 * (h1) + (m1));
    start_minutes = 60 * h1 + m1;
    end_minutes = 60 * h2 + m2;
    
    //@ assert end_minutes >= start_minutes;
    //@ assert end_minutes - start_minutes <= 60 * 23 + 59;
    
    ans = end_minutes - start_minutes - k;
    return ans;
}
