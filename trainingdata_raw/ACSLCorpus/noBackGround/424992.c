/*@
    requires (1 <= (x) <= 100);
    ensures \result == (((x) / 2) + ((x) % 2));
    ensures \result >= 1;
*/
unsigned int func(unsigned int x)
{
    unsigned int quotient = 0;
    unsigned int remainder = x;
    unsigned int divisor = 2;

    /*@
        loop invariant 0 <= quotient <= x / divisor;
        loop invariant 0 <= remainder <= x;
        loop invariant remainder + quotient * divisor == x;
        loop invariant (1 <= (x) <= 100);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }

    //@ assert quotient == x / 2;
    //@ assert remainder == x % 2;

    return quotient + remainder;
}

int main()
{
    return 0;
}
