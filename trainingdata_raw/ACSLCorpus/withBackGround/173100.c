#include <stddef.h>

/*@
    predicate valid_params(integer n, int *h) =
        1 <= n && n <= 20 &&
        \valid(h + (0 .. n-1)) &&
        \forall integer j; 0 <= j < n ==> 1 <= h[j] && h[j] <= 100;

    predicate loop_invariant(integer n, int *h, integer i, integer step, integer max_h) =
        0 <= i <= n-1 &&
        0 <= step <= i &&
        valid_params(n, h) &&
        0 <= max_h <= 100;

    lemma step_nonnegative:
        \forall integer n, i, step; 0 <= step <= i ==> step >= 0;

    lemma step_bound:
        \forall integer n, i, step; 0 <= step <= i && i <= n-1 ==> step <= n;
*/

/*@
    requires valid_params(n, h);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(size_t n, int *h) {
    int max_h = 0;
    int step = 0;
    size_t i = 0;

    /*@
        loop invariant loop_invariant(n, h, i, step, max_h);
        loop assigns i, step, max_h;
        loop variant n - i;
    */
    while (i < n - 1) {
        //@ assert 0 <= i < n-1;
        
        if (max_h < h[i]) {
            max_h = h[i];
        }

        if (max_h <= h[i + 1]) {
            i += 1;
            continue;
        } else {
            step += 1;
            max_h = h[i + 1];
            i += 1;
            continue;
        }
    }

    //@ assert 0 <= step <= n;
    return step;
}
