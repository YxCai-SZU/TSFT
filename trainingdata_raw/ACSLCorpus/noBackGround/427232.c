#include <stdbool.h>
#include <stdint.h>

/*@
  requires ((n) > 0 && (n) <= 100000 &&
      (k) > 0 && (k) <= 100);
  requires \valid(a + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000000000);
  ensures \result >= 0;
*/
uint32_t func(uint32_t n, uint32_t k, uint32_t *a) {
    uint32_t ans = 1000000000;
    uint32_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant ((n) > 0 && (n) <= 100000 &&
      (k) > 0 && (k) <= 100);
      loop invariant (\forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000000000);
      loop invariant ans >= 0;
      loop assigns i, ans;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n ==> a[i] > 0 && a[i] <= 1000000000;
        
        if (a[i] < k) {
            uint32_t diff = k - a[i];
            ans = (ans < diff) ? ans : diff;
        }
        
        i++;
    }
    
    //@ assert ans >= 0;
    return ans;
}
