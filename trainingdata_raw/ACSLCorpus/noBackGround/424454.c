#include <stdbool.h>
#include <stddef.h>

/*@
  requires n > 0;
  requires \valid(a + (0..n-1));
  assigns \nothing;
  ensures \result == true <==> (\forall integer i; 0 <= i < n ==> a[i] % 2 == 0);
*/
bool func(size_t n, int *a) {
    bool all_even = true;
    size_t i = 0;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant all_even == true <==> (\forall integer k; 0 <= k < (i) ==> (a)[k] % 2 == 0);
      loop assigns i, all_even;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (a[i] % 2 != 0) {
            all_even = false;
        }
        i++;
    }

    //@ assert all_even == true <==> (\forall integer k; 0 <= k < ((n)) ==> (a)[k] % 2 == 0);
    return all_even;
}
