#include <stdbool.h>

/*@
    predicate is_nonnegative(integer x) = x >= 0;
    predicate is_within_range(integer x) = 0 <= x && x <= 100;
    logic integer compute_k(integer a, integer p) = a * 3 + p;
    logic integer compute_result(integer a, integer p) = (a * 3 + p) / 2;
*/

/*@
    requires is_within_range(a) && is_within_range(p);
    ensures \result == compute_result(a, p);
*/
long func(long a, long p)
{
    long k;
    long ans;
    long temp_k;
    bool is_negative;

    k = a * 3 + p;
    ans = 0;
    temp_k = k;
    is_negative = false;

    if (temp_k < 0)
    {
        is_negative = true;
        temp_k = -temp_k;
    }

    /*@
        loop invariant 0 <= temp_k && temp_k <= compute_k(a, p);
        loop invariant ans == (compute_k(a, p) - temp_k) / 2;
        loop invariant is_within_range(a) && is_within_range(p);
        loop invariant k % 2 == temp_k % 2;
        loop assigns ans, temp_k;
        loop variant temp_k;
    */
    while (temp_k >= 2)
    {
        ans += 1;
        temp_k -= 2;
    }

    //@ assert k % 2 == temp_k % 2;
    //@ assert ans == compute_result(a, p);

    if (is_negative)
    {
        ans = -ans;
    }

    return ans;
}
