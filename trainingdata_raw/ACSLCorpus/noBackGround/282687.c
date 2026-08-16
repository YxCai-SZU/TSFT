#include <stdbool.h>
#include <stddef.h>

/*@
  requires n >= 1 && n <= 1000000;
  requires \valid(a + (0 .. len-1));
  requires ((len) >= 1 && (len) <= 10000 &&
      \forall integer i; 0 <= i < (len) ==> (a)[i] >= 1 && (a)[i] <= 10000);
  assigns \nothing;
  ensures \result >= -1 && \result <= n;
  ensures \result >= 0 || \result == -1;
*/
int func(int n, int *a, size_t len) {
    int sum = 0;
    size_t i = 0;

    /*@
      loop invariant (0 <= (i) <= (len) &&
      (sum) >= 0 &&
      (sum) <= (i) * 10000);
      loop invariant ((len) >= 1 && (len) <= 10000 &&
      \forall integer i; 0 <= i < (len) ==> (a)[i] >= 1 && (a)[i] <= 10000);
      loop invariant n >= 1 && n <= 1000000;
      loop assigns sum, i;
      loop variant len - i;
    */
    while (i < len) {
        //@ assert a[i] >= 1 && a[i] <= 10000;
        sum += a[i];
        i++;
        //@ assert sum <= i * 10000;
    }

    if (sum <= n) {
        //@ assert n - sum >= 0;
        return n - sum;
    } else {
        //@ assert sum - n >= 0;
        return -1;
    }
}
