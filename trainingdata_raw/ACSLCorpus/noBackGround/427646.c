#include <stddef.h>
/*@
    requires 2 <= k <= n <= 100000;
    requires \valid(a + (0 .. n-1));
    requires ((n) <= 100000 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= (n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (a)[i] != (a)[j]);
    assigns \nothing;
    ensures 1 <= \result <= n;
*/
size_t func(size_t n, size_t k, int *a) {
    size_t min = n + 1;
    size_t i = 0;
    /*@
        loop invariant 0 <= i <= k - 1;
        loop invariant 2 <= k <= n <= 100000;
        loop invariant ((n) <= 100000 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= (n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (a)[i] != (a)[j]);
        loop invariant min >= 1;
        loop assigns i, min;
        loop variant k - 1 - i;
    */
    while (i < k - 1) {
        size_t j = i + 1;
        /*@
            loop invariant i < j <= k;
            loop invariant 2 <= k <= n <= 100000;
            loop invariant ((n) <= 100000 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= (n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (a)[i] != (a)[j]);
            loop invariant min >= 1;
            loop assigns j, min;
            loop variant k - j;
        */
        while (j < k) {
            size_t sum = (size_t)a[i] + (size_t)a[j];
            if (sum < min) {
                min = sum;
            }
            j++;
        }
        i++;
    }
    size_t ans = (n - 1) / (k - 1) + 1;
    //@ assert 1 <= ans <= n;
    return (min <= ans) ? min : ans;
}
