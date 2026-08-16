#include <stdbool.h>

/*@
    predicate is_negative(integer k) = k < 0;
    logic integer manual_half(integer k) = k / 2;
*/

/*@
    requires 1 <= k <= 200;
    ensures \result == (800 * k) - (200 * (k / 2));
*/
long func(long k)
{
    long x;
    long half_k;
    long temp_k;
    bool is_negative;
    long y;
    long ans;

    x = 800 * k;
    half_k = 0;
    temp_k = k;
    is_negative = false;

    if (temp_k < 0)
    {
        is_negative = true;
        temp_k = -temp_k;
    }

    /*@
        loop invariant 0 <= temp_k <= 200;
        loop invariant half_k >= 0;
        loop invariant half_k <= k / 2;
        loop invariant temp_k == k - 2 * half_k;
        loop invariant 1 <= k <= 200;
        loop invariant half_k <= 100;
        loop assigns half_k, temp_k;
    */
    while (temp_k >= 2)
    {
        half_k += 1;
        temp_k -= 2;
    }

    if (is_negative)
    {
        half_k = -half_k;
    }

    y = 200 * half_k;
    ans = x - y;
    return ans;
}
