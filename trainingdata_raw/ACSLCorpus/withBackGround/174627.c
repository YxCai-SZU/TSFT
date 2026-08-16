#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_even(integer x) = (x & 1) == 0; */

/*@
  requires n >= 1 && n <= 200000;
  requires \valid(a + (0..n-1));
  requires \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 1000000;
  ensures \result >= 0;
  ensures \result <= n;
*/
int64_t func(int64_t n, const int64_t a[]) {
    int64_t count = 0;
    int64_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count <= i;
      loop invariant \forall integer k; 0 <= k < n ==> a[k] >= 1 && a[k] <= 1000000;
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        int64_t value = a[i];
        //@ assert value >= 1 && value <= 1000000;
        
        if ((value & 1) == 0) {
            count = count + 1;
        }
        i = i + 1;
    }
    return count;
}
