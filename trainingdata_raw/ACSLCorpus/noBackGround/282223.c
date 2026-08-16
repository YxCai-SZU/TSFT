#include <stdint.h>
#include <stdbool.h>

/*@
  requires ((n) > 0 && (n) <= 100000 &&
      (k) > 0 && (k) <= 1000000000);
  requires \valid(a + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000000000);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
uint32_t func(uint32_t n, uint32_t k, int32_t *a) {
    uint32_t count = 0;
    uint32_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count <= i;
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        int32_t value = a[i];
        //@ assert value > 0 && value <= 1000000000;
        
        if ((uint32_t)value <= k) {
            count = count + 1;
        }
        i = i + 1;
    }
    //@ assert 0 <= count <= n;
    return count;
}
