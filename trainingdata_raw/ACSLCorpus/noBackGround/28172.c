#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) >= 1 && (n) <= 100000 &&
      \forall size_t i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 1000000000);
  ensures \result >= 0 && \result <= (int)n;
*/
int func(size_t n, int *h)
{
    int res = 0;
    int acc = 0;
    int cur = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant res >= 0 && res <= (int)i;
        loop invariant acc >= 0 && acc <= (int)i;
        loop invariant ((n) >= 1 && (n) <= 100000 &&
      \forall size_t i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 1000000000);
        loop assigns i, res, acc, cur;
        loop variant n - i;
    */
    while (i < n) {
        int hi = h[i];
        if (hi >= cur) {
            //@ assert acc >= 0 && acc <= (int)i;
            res = (acc > res) ? acc : res;
            cur = hi;
            acc = 1;
        } else {
            acc += 1;
        }
        i += 1;
    }
    //@ assert acc >= 0 && acc <= (int)n;
    res = (acc > res) ? acc : res;
    return res;
}
