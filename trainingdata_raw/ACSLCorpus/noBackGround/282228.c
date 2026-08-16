#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) >= 1 && (n) <= 100000 &&
      (k) >= 1 && (k) <= 500);
  requires (\valid((h) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 500);
  ensures \result >= 0 && \result <= n;
  ensures \result == n || \result == 0;
*/
int func(int n, int k, int *h) {
    int cnt = 0;
    size_t index = 0;

    /*@
      loop invariant (0 <= (index) <= (n) &&
      0 <= (cnt) <= (integer)(index) &&
      (((n)) >= 1 && ((n)) <= 100000 &&
      ((k)) >= 1 && ((k)) <= 500) &&
      (\valid(((h)) + (0 .. ((n))-1)) &&
      \forall integer i; 0 <= i < ((n)) ==> ((h))[i] >= 1 && ((h))[i] <= 500));
      loop assigns cnt, index;
      loop variant n - index;
    */
    while (index < (size_t)n) {
        int i = h[index];
        //@ assert i >= 1 && i <= 500;
        if (i >= k) {
            cnt += 1;
        }
        index += 1;
    }

    if (cnt == 0) {
        return 0;
    } else {
        return n;
    }
}
