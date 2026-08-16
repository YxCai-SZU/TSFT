#include <stddef.h>
#include <stdbool.h>

/*@
  requires ((n) > 0 && (n) <= 100000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000000000);
  ensures ((\result) >= 1 && (\result) <= (n));
  assigns \nothing;
*/
size_t func(size_t n, const int *a) {
    size_t count = 1;
    size_t index = 0;
    int max = a[0];
    size_t i = 1;

    /*@
      loop invariant 1 <= i <= n;
      loop invariant count >= 1 && count <= i;
      loop invariant max == a[index];
      loop invariant index < n;
      loop assigns i, count, max, index;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert a[i] > 0 && a[i] <= 1000000000;
        if (a[i] >= max) {
            count += 1;
            max = a[i];
            index = i;
        }
        i += 1;
    }
    //@ assert ((count) >= 1 && (count) <= (n));
    return count;
}
