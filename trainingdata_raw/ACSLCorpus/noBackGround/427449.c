#include <stdint.h>
#include <stdbool.h>

/*@
  requires (2 <= (n) && (n) <= 100000);
  requires \valid(a + (0 .. n-1));
  requires (\forall integer j; 0 <= j < (n) ==> -1000000000 <= (a)[j] && (a)[j] <= 1000000000);
  assigns \nothing;
  ensures \result >= 0;
*/
int32_t func(uint32_t n, int64_t *a) {
    int64_t cnt = 0;
    int32_t b = 0;
    uint32_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n-1;
      loop invariant (2 <= (n) && (n) <= 100000);
      loop invariant \valid(a + (0 .. n-1));
      loop invariant (\forall integer j; 0 <= j < (n) ==> -1000000000 <= (a)[j] && (a)[j] <= 1000000000);
      loop invariant (0 <= (b) && (b) <= (i));
      loop assigns i, b;
      loop variant n - i;
    */
    while (i < n - 1) {
        //@ assert 0 <= i < n-1;
        if ((a[i] & 1) != 0 && (i & 1) == 0) {
            b += 1;
        }
        i += 1;
    }
    return b;
}
