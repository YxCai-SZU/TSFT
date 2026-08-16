#include <stdint.h>
#include <stdbool.h>

/*@
  requires n > 0 && n <= 100;
  requires \valid(numbers + (0 .. n-1));
  requires ((n) > 0 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> (numbers)[i] > 0 && (numbers)[i] <= 1000);
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= n * 1000;
*/
uint32_t func(uint32_t n, uint32_t numbers[]) {
    uint32_t tmp = 0;
    uint32_t i = 0;
    
    /*@
      loop invariant ((i) >= 0 && (i) <= (n) &&
      (tmp) >= 0 && (tmp) <= (i) * 1000 &&
      \forall integer j; 0 <= j < (n) ==> (numbers)[j] > 0 && (numbers)[j] <= 1000 &&
      \forall integer k; 0 <= k < (i) ==> (tmp) >= (numbers)[k] && (tmp) <= (tmp) + (numbers)[k]);
      loop assigns i, tmp;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert i >= 0 && i < n;
        tmp += numbers[i];
        i += 1;
    }
    
    uint32_t ans = tmp / 2;
    //@ assert ans >= 0 && ans <= n * 1000;
    return ans;
}
