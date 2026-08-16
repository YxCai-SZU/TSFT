#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_params(integer n, integer k, int *h) =
        n >= 1 && n <= 100000 &&
        k >= 1 && k <= 500 &&
        \valid(h + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 500;

    predicate loop_invariant(integer n, integer k, int *h, integer i, integer res) =
        0 <= i <= n &&
        0 <= res <= i &&
        res <= n &&
        \valid(h + (0 .. n-1)) &&
        \forall integer j; 0 <= j < n ==> h[j] >= 1 && h[j] <= 500 &&
        \forall integer j; 0 <= j < i ==> (h[j] >= k ==> res > 0);

    lemma res_bounds: \forall integer i, res; 0 <= res <= i ==> res >= 0 && res <= i;
*/

/*@
    requires valid_params(n, k, h);
    ensures \result >= 0 && \result <= n;
    ensures \forall integer i; 0 <= i < n ==> (h[i] >= k ==> \result > 0);
    assigns \nothing;
*/
int func(int n, int k, int *h)
{
    int res = 0;
    int i = 0;

    /*@
        loop invariant loop_invariant(n, k, h, i, res);
        loop assigns i, res;
        loop variant n - i;
    */
    while (i < n)
    {
        int hi = h[i];
        if (hi >= k)
        {
            res += 1;
        }
        i += 1;

        //@ assert res >= 0 && res <= i;
    }
    return res;
}
