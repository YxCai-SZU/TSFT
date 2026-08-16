#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_array(integer n, int *a) =
        n >= 1 && n <= 200000 &&
        \valid(a + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> 1 <= a[i] <= n &&
        \forall integer i, j; 0 <= i < j < n ==> a[i] != a[j];
*/

/*@
    requires valid_array(n, a);
    ensures \result >= -1 && \result <= (int)n;
    assigns \nothing;
*/
int func(size_t n, const int *a) {
    int ret = 0;
    int prev;
    size_t i = 0;

    //@ assert valid_array(n, a);
    prev = a[0];

    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= ret <= (int)i;
        loop invariant 1 <= prev <= (int)n;
        loop assigns i, ret, prev;
        loop variant n - i;
    */
    while (i < n) {
        if (prev >= a[i]) {
            ret += 1;
            prev = a[i];
        }
        i += 1;
    }

    if (ret == 1) {
        return -1;
    } else {
        return ret;
    }
}
