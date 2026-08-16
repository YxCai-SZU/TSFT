#include <stdbool.h>
/*@
    predicate valid_params(integer n, int *h) =
        n >= 1 && n <= 20 &&
        \valid(h + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 100;

    predicate loop_invariant(integer i, integer n, int *h, integer max, integer count) =
        0 <= i && i <= n &&
        0 <= count && count <= i &&
        \valid(h + (0 .. n-1)) &&
        \forall integer j; 0 <= j < n ==> h[j] >= 1 && h[j] <= 100 &&
        \forall integer k; 0 <= k < i ==> max >= h[k];
*/

/*@
    requires valid_params(n, h);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int *h) {
    int max = 0;
    int count = 0;
    int i = 0;
    /*@
        loop invariant loop_invariant(i, n, h, max, count);
        loop assigns i, max, count;
        loop variant n - i;
    */
    while (i < n) {
        int value = h[i];
        //@ assert 0 <= i && i < n;
        //@ assert value >= 1 && value <= 100;
        if (max <= value) {
            max = value;
            count = count + 1;
        }
        i = i + 1;
    }
    return count;
}
