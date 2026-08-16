#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_even(integer n) = n % 2 == 0; */
/*@ predicate is_odd(integer n) = n % 2 != 0; */

/*@
  requires 1 <= n <= 100;
  requires \valid(a + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 100;
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int func(uint32_t n, const uint32_t a[]) {
    int count = 0;
    uint32_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count <= i;
      loop invariant \forall integer j; 0 <= j < n ==> 1 <= a[j] <= 100;
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        if (i % 2 == 0) {
            if (a[i] % 2 != 0) {
                count += 1;
            }
        }
        i += 1;
    }
    return count;
}
