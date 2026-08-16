#include <stddef.h>
#include <stdbool.h>

/*@
    predicate distinct_between{L}(size_t *ps, integer start, integer end) =
        \forall integer i, j; start <= i < j < end ==> ps[i] != ps[j];

    predicate valid_range{L}(size_t *ps, integer n) =
        \forall integer i; 0 <= i < n ==> 1 <= ps[i] <= n;

    predicate distinct_all{L}(size_t *ps, integer n) =
        distinct_between(ps, 0, n);
*/

/*@
    requires n >= 3 && n <= 200000;
    requires \valid(ps + (0 .. n-1));
    requires valid_range(ps, n);
    requires distinct_all(ps, n);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
size_t func(size_t n, size_t *ps) {
    size_t ans = 0;
    size_t i = 2;

    /*@
        loop invariant 2 <= i <= n;
        loop invariant 0 <= ans <= i;
        loop invariant distinct_between(ps, 0, i);
        loop invariant valid_range(ps, n);
        loop invariant distinct_all(ps, n);
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert i >= 2 && i < n;
        if (ps[i-1] < ps[i-2] && ps[i] < ps[i-1]) {
            ans += 1;
        } else if (ps[i-1] < ps[i] && ps[i-2] < ps[i-1]) {
            ans += 1;
        }
        i += 1;
    }

    return ans;
}
