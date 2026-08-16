#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_params(integer n, int *h) =
        n >= 1 && n <= 20 &&
        \valid(h + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 100;

    predicate loop_invariant(integer n, int *h, integer idx, integer res) =
        idx >= 0 && idx <= n &&
        res >= 0 && res <= idx &&
        valid_params(n, h);
*/

/*@
    requires valid_params(n, h);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int *h) {
    int max = 0;
    int res = 0;
    size_t index = 0;

    //@ ghost int old_n = n;
    //@ ghost int *old_h = h;

    /*@
        loop invariant loop_invariant(old_n, old_h, index, res);
        loop assigns max, res, index;
        loop variant old_n - index;
    */
    while (index < (size_t)n) {
        int i = h[index];
        if (max <= i) {
            max = i;
        } else {
            res += 1;
        }
        index += 1;
    }
    return res;
}
