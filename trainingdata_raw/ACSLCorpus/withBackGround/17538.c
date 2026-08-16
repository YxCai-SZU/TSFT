#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_valid_array(int32_t* a, integer n) =
      n >= 2 && n <= 200000 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 1000000000;
*/

/*@ logic integer abs_diff(integer x, integer y) =
      x >= y ? x - y : y - x;
*/

/*@ lemma result_bounds:
      \forall integer n, int32_t* a, int32_t res;
      is_valid_array(a, n) && res >= 0 && res <= 1000000000 ==> 
      (res >= 0 && res <= 1000000000);
*/

/*@
  requires is_valid_array(a, n);
  ensures \result >= 0 && \result <= 1000000000;
*/
int32_t func(uint32_t n, int32_t* a)
{
  int32_t result = 1000000000;
  uint32_t i = 1;
  
  /*@
    loop invariant 1 <= i <= n;
    loop invariant \valid(a + (0 .. n-1));
    loop invariant result >= 0 && result <= 1000000000;
    loop assigns i, result;
    loop variant n - i;
  */
  while (i < n) {
    int32_t diff;
    int32_t delta = a[i] - a[i-1];
    
    //@ assert delta >= -1000000000 && delta <= 1000000000;
    
    if (delta < 0) {
      diff = -delta;
    } else {
      diff = delta;
    }
    
    //@ assert diff == abs_diff(a[i], a[i-1]);
    
    if (diff < result) {
      result = diff;
    }
    
    i = i + 1;
  }
  
  return result;
}
