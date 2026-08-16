#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        0 <= a && 0 <= b && 0 <= c &&
        1 <= k && k <= a + b + c &&
        k <= 2000000000;

    logic integer final_points(integer a, integer b, integer c, integer k) =
        k <= a ? k :
        k <= a + b ? a :
        a - (k - a - b);
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result <= k;
    ensures \result == final_points(a, b, c, k);
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t k_remaining;
    int32_t points;

    k_remaining = k;
    points = 0;

    //@ assert k_remaining == k && points == 0;

    if (k_remaining > a)
    {
        points += a;
        k_remaining -= a;
        //@ assert points == a && k_remaining == k - a;
    }
    else
    {
        points += k_remaining;
        k_remaining = 0;
        //@ assert points == k && k_remaining == 0;
    }

    if (k_remaining > b)
    {
        k_remaining -= b;
        //@ assert k_remaining == k - a - b || k_remaining == k - b;
    }
    else
    {
        k_remaining = 0;
        //@ assert k_remaining == 0;
    }

    if (k_remaining > c)
    {
        points -= c;
        k_remaining -= c;
        //@ assert points == a - c && k_remaining == k - a - b - c;
    }
    else
    {
        points -= k_remaining;
        k_remaining = 0;
        //@ assert k_remaining == 0;
    }

    //@ assert k_remaining == 0;
    //@ assert points <= k;

    return points;
}
