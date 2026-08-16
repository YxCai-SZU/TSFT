#include <stddef.h>
#include <stdint.h>

/*@
  requires ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 500);
  requires (\valid((h) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= n;
*/
int32_t func(size_t n, size_t k, const int64_t *h) {
    int32_t ans = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant ans >= 0;
      loop invariant ans <= i;
      loop invariant \forall integer j; 0 <= j < i ==> h[j] >= 1 && h[j] <= 500;
      loop invariant ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 500);
      loop invariant (\valid((h) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
      loop assigns ans, i;
      loop variant n - i;
    */
    while (i < n) {
        if (h[i] >= (int64_t)k) {
            ans += 1;
        }
        i += 1;
        //@ assert ans <= i;
    }
    return ans;
}
