#include <limits.h>

/*@
    predicate valid_params(integer n, integer a, integer b) =
        1 <= n <= 20 && 1 <= a <= 50 && 1 <= b <= 50;

    logic integer safe_product(integer a, integer n) = a * n;

    lemma product_bounds:
        \forall integer n, integer a;
        valid_params(n, a, 1) ==> 1 <= safe_product(a, n) <= 1000;
*/

/*@
    requires valid_params(n, a, b);
    ensures \result == a * n || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
int func(int n, int a, int b)
{
    int ans;
    int i;

    //@ assert 1 <= a * n <= 1000;

    if (a * n < b)
        ans = a * n;
    else
        ans = b;

    i = 0;
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant valid_params(n, a, b);
        loop invariant 1 <= a * n <= 1000;
        loop assigns i;
        loop variant 10 - i;
    */
    while (i < 10)
    {
        i = i + 1;
    }

    return ans;
}
