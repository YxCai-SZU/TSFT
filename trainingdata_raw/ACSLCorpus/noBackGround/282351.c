#include <stddef.h>

/*@
  requires \valid(a + (0 .. n-1));
  requires ((n) >= 1 && (n) <= 200000 &&
      \forall size_t j; 0 <= j < (n) ==> (a)[j] >= 1 && (a)[j] <= (int)(n));
  assigns \nothing;
  ensures \result <= n;
*/
size_t func(size_t n, int *a) {
    size_t count = 0;
    size_t index = 1;
    size_t i = 0;
    
    /*@
      loop invariant i <= n;
      loop invariant count <= i;
      loop invariant index >= 1;
      loop invariant index <= i + 1;
      loop invariant ((n) >= 1 && (n) <= 200000 &&
      \forall size_t j; 0 <= j < (n) ==> (a)[j] >= 1 && (a)[j] <= (int)(n));
      loop assigns i, count, index;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert i < n && i <= n && count <= i && index >= 1 && index <= i + 1;
        if (a[i] == (int)index) {
            index += 1;
            count += 1;
        }
        i += 1;
    }
    return count;
}
