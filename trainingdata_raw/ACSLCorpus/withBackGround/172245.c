#include <stddef.h>
#include <stdint.h>

/*@ predicate valid_params(size_t n, int64_t x, int64_t *l) =
    n >= 1 && n <= 100 &&
    x >= 1 && x <= 10000 &&
    \valid(l + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==> l[i] >= 1 && l[i] <= 100;
*/

/*@
    requires valid_params(n, x, l);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
size_t func(size_t n, int64_t x, const int64_t *l) {
    int64_t d = 0;
    size_t count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant d >= 0;
        loop invariant d <= i * 100;
        loop invariant \forall integer j; 0 <= j < i ==> l[j] >= 1 && l[j] <= 100;
        loop assigns i, count, d;
        loop variant n - i;
    */
    while (i < n && d <= x) {
        //@ assert d <= x;
        count += 1;
        d += l[i];
        i += 1;
    }
    //@ assert count >= 0 && count <= n;
    return count;
}
