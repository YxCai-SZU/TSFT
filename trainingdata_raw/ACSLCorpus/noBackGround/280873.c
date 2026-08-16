#include <stdbool.h>
#include <stddef.h>

/*@ requires n > 0 && n <= 200000;
    requires \valid(a + (0 .. n-1));
    requires ((n) > 0 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(size_t n, int *a) {
    int count = 0;
    size_t i = 0;
    
    /*@ loop invariant (0 <= (i) <= (n) &&
      0 <= (count) <= (i) &&
      \forall integer k; 0 <= k < (i) && k % 2 == 0 ==> ((a)[k] & 1) == 1 ==> (count) > 0);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        if (i % 2 == 0) {
            if ((a[i] & 1) == 1) {
                count += 1;
            }
        }
        i += 1;
    }
    return count;
}
