#include <stdint.h>
#include <stdbool.h>

/*@
  requires ((n) >= 1 && (n) <= 200000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
  ensures \result >= 0 && \result <= n;
  assigns \nothing;
*/
int32_t func(uint32_t n, int64_t *a)
{
  int64_t prev = -1;
  int32_t cnt = 0;
  uint32_t i = 0;
  
  /*@
    loop invariant (0 <= (i) && (i) <= (n) &&
      0 <= (cnt) && (cnt) <= (i) &&
      \valid((a) + (0 .. (n)-1)) &&
      (prev) >= -1 &&
      (prev) <= 1000000000);
    loop assigns i, cnt, prev;
    loop variant n - i;
  */
  while (i < n)
  {
    int64_t ai = a[i];
    
    //@ assert ai >= 1 && ai <= 1000000000;
    
    if (ai > prev)
    {
      prev = ai;
      cnt = cnt + 1;
    }
    
    i = i + 1;
  }
  
  //@ assert cnt >= 0;
  //@ assert cnt <= n;
  
  return cnt;
}
