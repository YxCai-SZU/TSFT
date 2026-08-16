#include <stddef.h>
#include <stdbool.h>

/*@
  requires ((n) >= 1 && (n) <= 200000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer j; 0 <= j < (n) ==> (a)[j] >= 1 && (a)[j] <= 1000000);
  assigns \nothing;
  ensures \result >= 0 && \result <= n;
*/
size_t func(size_t n, int *a) {
    size_t count = 0;
    size_t count2 = 0;
    size_t i = 0;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant count <= i;
      loop invariant count2 <= i;
      loop assigns i, count, count2;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (i == 0) {
            count += 1;
            count2 = 1;
        } else {
            size_t j = i - 1;
            //@ assert 0 <= j < n;
            if (a[i] <= a[j]) {
                if (count2 >= 1) {
                    count += 1;
                    count2 = 1;
                } else {
                    count2 = 1;
                }
            } else {
                count2 += 1;
            }
        }
        i += 1;
        //@ assert count <= i;
    }
    //@ assert count <= n;
    return count;
}
