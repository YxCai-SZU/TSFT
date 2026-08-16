#include <stdbool.h>
#include <stddef.h>

/*@ requires 1 <= n <= 1000000;
    requires 1 <= m <= 10000;
    requires \valid(a + (0..m-1));
    requires (\forall integer i; 0 <= i < (m) ==> 1 <= (a)[i] <= 10000);
    ensures \result >= -1;
    ensures \result <= n;
*/
int func(int n, int m, int *a) {
    int sum = 0;
    size_t i = 0;

    /*@ loop invariant (0 <= (i) <= (m) &&
      (sum) >= 0 &&
      (sum) <= (i) * 10000 &&
      \forall integer k; 0 <= k < (i) ==> 1 <= (a)[k] <= 10000);
        loop assigns sum, i;
        loop variant m - i;
    */
    while (i < (size_t)m) {
        //@ assert 0 <= i < m;
        sum += a[i];
        i++;
    }

    if (n >= sum) {
        return n - sum;
    } else {
        return -1;
    }
}
