/*@
    requires (1 <= (x) && (x) <= 1000000);
    ensures \result == 1000 * (x / 1000) || \result == x;
*/
int func(int x)
{
    int quotient;
    int remainder;
    int divisor;
    int ans;

    quotient = 0;
    remainder = x;
    divisor = 1000;

    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= x / 1000;
        loop invariant remainder >= 0;
        loop invariant remainder + divisor * quotient == x;
        loop invariant (1 <= (x) && (x) <= 1000000);
        loop invariant quotient <= 1000 * (x / 1000) / 1000;
        loop assigns remainder, quotient;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }

    ans = quotient * 1000;

    if (remainder >= 500)
    {
        //@ assert ans == 1000 * (x / 1000) || x == x;
        return x;
    }
    else
    {
        //@ assert ans == 1000 * (x / 1000) || ans == x;
        return ans;
    }
}
