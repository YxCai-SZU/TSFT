/*@
    requires (1 <= (x) <= 1000);
    ensures \result >= 1 && \result <= 1000;
    ensures \result * 3 >= x && x * 3 >= \result;
*/
int func(int x)
{
    int quotient;
    int remainder;
    int divisor;
    int result;

    quotient = 0;
    remainder = x;
    divisor = 3;

    /*@
        loop invariant (1 <= (x) <= 1000);
        loop invariant (0 <= (quotient) <= (x) / (divisor) &&
        (remainder) == (x) - (quotient) * (divisor) &&
        (remainder) >= 0);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        quotient += 1;
        remainder -= divisor;
        //@ assert remainder == x - quotient * divisor;
    }

    //@ assert remainder == x - quotient * divisor;
    //@ assert remainder >= 0;
    //@ assert 0 <= quotient <= x / divisor;

    if (remainder == 0)
    {
        result = quotient;
    }
    else
    {
        result = quotient + 1;
    }

    //@ assert result == ((remainder) == 0 ? (quotient) : (quotient) + 1);
    //@ assert result >= 1 && result <= 1000;
    //@ assert result * 3 >= x;
    //@ assert x * 3 >= result;

    return result;
}
