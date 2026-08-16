#include <stdbool.h>

/*@
    predicate is_even_parity(integer k, integer temp_k) =
        temp_k % 2 == k % 2;
 */

/*@
    requires a >= -1000000000 && a <= 1000000000;
    requires b >= -1000000000 && b <= 1000000000;
    requires c >= -1000000000 && c <= 1000000000;
    requires k >= 0 && k <= 100000000000000000;
    ensures \result == a - b || \result == b - a;
 */
int func(int a, int b, int c, long long k)
{
    bool is_even;
    long long temp_k;
    int ans;

    is_even = true;
    temp_k = k;

    /*@
        loop invariant 0 <= temp_k <= k;
        loop invariant a >= -1000000000 && a <= 1000000000;
        loop invariant b >= -1000000000 && b <= 1000000000;
        loop invariant c >= -1000000000 && c <= 1000000000;
        loop invariant k >= 0 && k <= 100000000000000000;
        loop invariant is_even_parity(k, temp_k);
        loop assigns temp_k, is_even;
        loop variant temp_k;
     */
    while (temp_k > 0)
    {
        if (temp_k == 1)
        {
            is_even = false;
            break;
        }
        temp_k -= 2;
    }

    if (is_even)
    {
        ans = a - b;
    }
    else
    {
        ans = b - a;
    }

    //@ assert (is_even && ans == a - b) || (!is_even && ans == b - a);

    return ans;
}
