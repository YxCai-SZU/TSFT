#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer k, int *h) =
        n >= 1 && n <= 100000 &&
        k >= 1 && k <= 500 &&
        \valid(h + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 500;

    predicate ans_invariant(integer n, integer k, int *h, integer index, integer ans) =
        index >= 0 && index <= n &&
        ans >= 0 && ans <= index &&
        \forall integer i; 0 <= i < index ==> h[i] >= 1 && h[i] <= 500 &&
        \forall integer i; 0 <= i < index ==> (h[i] >= k ==> ans > 0);
*/

/*@
    requires valid_params(n, k, h);
    ensures \result >= 0 && \result <= n;
    ensures \forall integer i; 0 <= i < n ==> (h[i] >= k ==> \result > 0);
    assigns \nothing;
*/
int func(int n, int k, int *h)
{
    int ans = 0;
    int index = 0;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant ans >= 0 && ans <= index;
        loop invariant \forall integer i; 0 <= i < index ==> h[i] >= 1 && h[i] <= 500;
        loop invariant \forall integer i; 0 <= i < index ==> (h[i] >= k ==> ans > 0);
        loop invariant valid_params(n, k, h);
        loop assigns ans, index;
        loop variant n - index;
    */
    while (index < n)
    {
        if (k <= h[index])
        {
            ans += 1;
        }
        index += 1;
    }

    //@ assert \forall integer i; 0 <= i < n ==> (h[i] >= k ==> ans > 0);
    return ans;
}
