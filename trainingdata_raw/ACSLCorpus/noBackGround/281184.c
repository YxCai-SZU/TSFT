#include <stddef.h>
#include <stdbool.h>

/*@
  requires 1 <= n;
  requires \valid(a + (0 .. n-1));
  requires \forall integer k; 0 <= k < n ==> (1 <= (a[k]) && (a[k]) <= 100);
  ensures \result <= n;
  ensures \forall integer i; 0 <= i < n && (((i) + 1) % 2 == 1) && ((a[i]) % 2 == 1) ==> \result > 0;
*/
size_t func(size_t n, const size_t a[]) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant count <= i;
      loop invariant \forall integer j; 0 <= j < i && (((j) + 1) % 2 == 1) && ((a[j]) % 2 == 1) ==> count > 0;
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        size_t x = a[i];
        if (((i + 1) % 2 == 1) && (x % 2 == 1)) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
