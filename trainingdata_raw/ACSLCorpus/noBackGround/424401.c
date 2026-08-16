/*@
    requires (1 <= (x) && (x) <= 1000);
    ensures (1 <= (\result) && (\result) <= 1000);
    ensures ((\result) * 3) >= x;
    ensures ((\result) * 3) <= ((1000) * 3);
*/
int func(int x)
{
    int quotient;
    int remainder;
    int divisor;

    quotient = 0;
    remainder = x;
    divisor = 3;

    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= x / divisor;
        loop invariant remainder == x - quotient * divisor;
        loop invariant (1 <= (x) && (x) <= 1000);
        loop assigns quotient, remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        quotient = quotient + 1;
        remainder = remainder - divisor;
    }

    if (remainder > 0)
    {
        quotient = quotient + 1;
    }

    //@ assert (1 <= (quotient) && (quotient) <= 1000);
    //@ assert ((quotient) * 3) >= x;
    //@ assert ((quotient) * 3) <= ((1000) * 3);
    return quotient;
}
