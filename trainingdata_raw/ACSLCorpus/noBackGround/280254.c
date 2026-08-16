#include <stddef.h>
#include <stdbool.h>

/*@
  requires ((n) >= 1 && (n) <= 100000 &&
      \forall integer i; 0 <= i < (n) ==> (1 <= ((h)[i]) && ((h)[i]) <= 1000000000));
  ensures 0 <= \result && \result <= n;
  assigns \nothing;
*/
size_t func(size_t n, int *h) {
    size_t cur;
    size_t cnt;
    size_t i;
    
    cur = (size_t)h[0];
    cnt = 0;
    i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= cnt <= i;
      loop invariant ((n) >= 1 && (n) <= 100000 &&
      \forall integer i; 0 <= i < (n) ==> (1 <= ((h)[i]) && ((h)[i]) <= 1000000000));
      loop invariant \forall integer k; 0 <= k < i ==> (1 <= (h[k]) && (h[k]) <= 1000000000);
      loop assigns i, cur, cnt;
    */
    while (i < n) {
        //@ assert (0 <= (i) && (i) < (n));
        if ((size_t)h[i] >= cur) {
            cur = (size_t)h[i];
            cnt = cnt + 1;
        }
        i = i + 1;
    }
    return cnt;
}
