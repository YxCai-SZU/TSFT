#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(h + (0 .. n-1));
  requires ((n) >= 1 && (n) <= 20 &&
      \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 100);
  assigns \nothing;
  ensures \result >= 0 && \result <= n;
*/
int func(int n, int *h) {
    int max_h = 0;
    int ans = 0;
    size_t index = 0;

    /*@
      loop invariant (0 <= (index) <= (n) &&
      0 <= (ans) <= (index) &&
      (((n)) >= 1 && ((n)) <= 20 &&
      \forall integer i; 0 <= i < ((n)) ==> ((h))[i] >= 1 && ((h))[i] <= 100) &&
      \forall integer k; 0 <= k < (index) ==> (max_h) >= (h)[k]);
      loop assigns max_h, ans, index;
      loop variant n - index;
    */
    while (index < (size_t)n) {
        int x = h[index];
        if (max_h < x) {
            max_h = x;
        }
        //@ assert max_h >= h[index];
        if (max_h <= x) {
            ans += 1;
        }
        index += 1;
    }
    return ans;
}
