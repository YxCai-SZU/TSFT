#include <stddef.h>
#include <stdbool.h>

/*@
  requires ((n) >= 1 && (n) <= 100 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 100);
  ensures \result >= -1 && \result <= n;
  assigns \nothing;
*/
int func(size_t n, int *a) {
    int count = 0;
    int break_count = 0;
    size_t i = 0;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant count >= 0;
      loop invariant break_count >= 0;
      loop invariant count + break_count == (int)i;
      loop invariant \forall integer j; 0 <= j < i ==> a[j] >= 1 && a[j] <= 100;
      loop invariant n >= 1 && n <= 100;
      loop invariant count <= (int)i;
      loop invariant break_count <= (int)i;
      loop invariant i <= n;
      loop assigns i, count, break_count;
      loop variant n - i;
    */
    while (i < n) {
        int ai = a[i];
        if (ai < (int)i + 1) {
            break_count += 1;
        } else {
            count += 1;
        }
        i += 1;
    }

    if (count == 0) {
        return -1;
    } else {
        return count;
    }
}
