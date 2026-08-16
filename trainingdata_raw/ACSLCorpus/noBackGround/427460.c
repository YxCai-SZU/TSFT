#include <stddef.h>
#include <stdint.h>

/*@
  requires ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 500);
  requires \valid_read(h + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int32_t func(size_t n, size_t k, const int64_t *h) {
    int32_t ans = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= ans <= i;
      loop invariant (\forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
      loop assigns ans, i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (h[i] >= (int64_t)k) {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}
