#include <stddef.h>
#include <stdbool.h>

/*@
    requires n >= 1;
    requires 1 <= k <= 500;
    requires \valid(h+(0..n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= h[i] <= 500;
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
size_t func(size_t n, size_t k, const size_t h[]) {
    size_t res = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant res <= i;
        loop invariant (1 <= (n) &&
        1 <= (k) <= 500 &&
        \valid((h)+(0..(n)-1)) &&
        \forall integer j; 0 <= j < (n) ==> 1 <= (h)[j] <= 500);
        loop assigns i, res;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (h[i] >= k) {
            res += 1;
        }
        i += 1;
    }
    return res;
}
