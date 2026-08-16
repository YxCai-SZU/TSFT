/*@
    requires (1 <= (x) <= 100 &&
        1 <= (y) <= 100 &&
        (y) % 2 == 0);
    ensures \result >= 0;
    ensures \result == (x + y) / 2;
    assigns \nothing;
*/
int func(int x, int y)
{
    int ans;
    int numerator;
    int quotient;
    int remainder;
    int divisor;
    int is_negative;

    ans = 0;
    numerator = x + y;
    quotient = 0;
    remainder = numerator;
    divisor = 2;
    is_negative = 0;

    if (remainder < 0)
    {
        is_negative = 1;
        remainder = -remainder;
    }

    /*@
        loop invariant 0 <= remainder <= x + y;
        loop invariant quotient >= 0;
        loop invariant remainder == numerator - quotient * divisor;
        loop invariant 1 <= x <= 100;
        loop invariant 1 <= y <= 100;
        loop invariant y % 2 == 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }

    if (is_negative)
    {
        quotient = -quotient;
    }

    ans = quotient;
    return ans;
}
