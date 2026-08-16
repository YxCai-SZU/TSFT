/*@
    predicate is_valid_range(integer k) = 1 <= k <= 1000;
    predicate loop_inv(integer k, integer q, integer r, integer d) =
        q >= 0 && r >= 0 && r == k - d * q;
    logic integer division_result(integer k, integer d) = k / d;
*/

/*@
    requires is_valid_range(k);
    ensures \result == division_result(k, 3);
    assigns \nothing;
*/
int func(int k)
{
    int quotient;
    int remainder;
    int divisor;
    int is_negative;

    quotient = 0;
    remainder = k;
    divisor = 3;
    is_negative = 0;

    if (k < 0)
    {
        remainder = -remainder;
        is_negative = 1;
    }

    /*@
        loop invariant loop_inv(k, quotient, remainder, divisor);
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder == k - divisor * quotient;
        remainder -= divisor;
        quotient += 1;
    }

    if (is_negative)
    {
        quotient = -quotient;
    }

    //@ assert quotient == k / 3;
    return quotient;
}
