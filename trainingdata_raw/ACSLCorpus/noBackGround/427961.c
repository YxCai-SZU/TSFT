/*@
    requires 1 <= n <= 10000;
    requires 0 <= a <= 1000;
    ensures \result == (n % 500 <= a);
*/
_Bool func(unsigned long n, unsigned long a)
{
    unsigned long quotient;
    unsigned long remainder;

    quotient = 0;
    remainder = n;

    /*@
        loop invariant 0 <= quotient;
        loop invariant remainder <= n;
        loop invariant ((remainder) == (n) - 500 * (quotient));
        loop invariant quotient <= n / 500;
        loop assigns remainder, quotient;
    */
    while (remainder >= 500)
    {
        //@ assert ((remainder) == (n) - 500 * (quotient));
        remainder -= 500;
        quotient += 1;
        //@ assert ((remainder) == (n) - 500 * (quotient));
    }

    //@ assert remainder == n % 500;
    return remainder <= a;
}
