#include <limits.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 1000;

    logic integer multiply_by_3(integer a) = a * 3;

    lemma quotient_bound: \forall integer x, q, r, d;
        is_valid_range(x) && d == 3 && r >= 0 && q >= 0 && r + q * d == x ==> q <= x / d;
*/

/*@
    requires is_valid_range(x);
    ensures \result >= 0;
    ensures \result <= 1000;
    ensures multiply_by_3(\result) <= x;
    assigns \nothing;
*/
int func(int x)
{
    int quotient = 0;
    int remainder;
    int divisor = 3;

    if (x < 0)
    {
        remainder = -x;
    }
    else
    {
        remainder = x;
    }

    /*@
        loop invariant 0 <= quotient <= 1000;
        loop invariant 0 <= remainder <= 1000;
        loop invariant remainder + quotient * divisor == x;
        loop invariant is_valid_range(x);
        loop invariant quotient <= x / divisor;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }

    if (x < 0)
    {
        quotient = -quotient;
    }

    //@ assert quotient <= x / divisor;

    return quotient;
}
