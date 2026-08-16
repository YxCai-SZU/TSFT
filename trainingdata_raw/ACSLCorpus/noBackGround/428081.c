/*@
    requires 1 <= N <= 1000;
    ensures \result == N / 3;
    assigns \nothing;
*/
long func(long N)
{
    long quotient = 0;
    long remainder = N;
    const long divisor = 3;

    /*@
        loop invariant (0 <= (quotient) &&
        (quotient) <= (N) / 3 &&
        0 <= (remainder) &&
        (remainder) <= (N) &&
        (remainder) == (N) - (quotient) * 3 &&
        1 <= (N) <= 1000);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder == N - quotient * 3;
        quotient += 1;
        remainder -= divisor;
    }

    //@ assert quotient == N / 3;
    return quotient;
}
