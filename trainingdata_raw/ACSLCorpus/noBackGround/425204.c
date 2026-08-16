/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result >= 0;
    ensures \result <= n;
*/
int func(int n)
{
    int quotient = 0;
    int remainder = n;
    int count = 0;
    int result;

    //@ assert (1 <= (n) && (n) <= 10000);
    //@ assert (0 <= (remainder) && (remainder) <= (n));
    //@ assert count == 0;
    //@ assert n == remainder + count * 1000 + quotient;
    //@ assert (0 <= (quotient) && (quotient) <= (n) - (remainder));

    /*@
        loop invariant (1 <= (n) && (n) <= 10000);
        loop invariant (0 <= (remainder) && (remainder) <= (n));
        loop invariant (0 <= (count) && (count) <= (n) / (1000));
        loop invariant ((n) == (remainder) + (count) * (1000) + (quotient));
        loop invariant (0 <= (quotient) && (quotient) <= (n) - (remainder));
        loop assigns count, remainder;
    */
    while (remainder >= 1000)
    {
        //@ assert remainder >= 1000;
        count += 1;
        remainder -= 1000;
        //@ assert (0 <= (remainder) && (remainder) <= (n));
        //@ assert ((n) == (remainder) + (count) * (1000) + (quotient));
    }

    quotient = count * 1000;
    remainder = n - quotient;

    //@ assert (0 <= (remainder) && (remainder) <= (n));
    //@ assert (0 <= (quotient) && (quotient) <= (n) - (remainder));

    count = 0;

    /*@
        loop invariant (1 <= (n) && (n) <= 10000);
        loop invariant (0 <= (remainder) && (remainder) <= (n));
        loop invariant (0 <= (count) && (count) <= (n) / (100));
        loop invariant ((n) == (remainder) + (count) * (100) + (quotient));
        loop invariant (0 <= (quotient) && (quotient) <= (n) - (remainder));
        loop assigns count, remainder;
    */
    while (remainder >= 100)
    {
        //@ assert remainder >= 100;
        count += 1;
        remainder -= 100;
        //@ assert (0 <= (remainder) && (remainder) <= (n));
        //@ assert ((n) == (remainder) + (count) * (100) + (quotient));
    }

    quotient += count * 100;
    remainder = n - quotient;

    //@ assert (0 <= (remainder) && (remainder) <= (n));
    //@ assert (0 <= (quotient) && (quotient) <= (n) - (remainder));

    count = 0;

    /*@
        loop invariant (1 <= (n) && (n) <= 10000);
        loop invariant (0 <= (remainder) && (remainder) <= (n));
        loop invariant (0 <= (count) && (count) <= (n) / (50));
        loop invariant ((n) == (remainder) + (count) * (50) + (quotient));
        loop invariant (0 <= (quotient) && (quotient) <= (n) - (remainder));
        loop assigns count, remainder;
    */
    while (remainder >= 50)
    {
        //@ assert remainder >= 50;
        count += 1;
        remainder -= 50;
        //@ assert (0 <= (remainder) && (remainder) <= (n));
        //@ assert ((n) == (remainder) + (count) * (50) + (quotient));
    }

    quotient += count * 50;
    remainder = n - quotient;

    //@ assert (0 <= (remainder) && (remainder) <= (n));
    //@ assert (0 <= (quotient) && (quotient) <= (n) - (remainder));

    count = 0;

    /*@
        loop invariant (1 <= (n) && (n) <= 10000);
        loop invariant (0 <= (remainder) && (remainder) <= (n));
        loop invariant (0 <= (count) && (count) <= (n) / (10));
        loop invariant ((n) == (remainder) + (count) * (10) + (quotient));
        loop invariant (0 <= (quotient) && (quotient) <= (n) - (remainder));
        loop assigns count, remainder;
    */
    while (remainder >= 10)
    {
        //@ assert remainder >= 10;
        count += 1;
        remainder -= 10;
        //@ assert (0 <= (remainder) && (remainder) <= (n));
        //@ assert ((n) == (remainder) + (count) * (10) + (quotient));
    }

    quotient += count * 10;
    remainder = n - quotient;

    //@ assert (0 <= (remainder) && (remainder) <= (n));
    //@ assert (0 <= (quotient) && (quotient) <= (n) - (remainder));

    count = 0;

    /*@
        loop invariant (1 <= (n) && (n) <= 10000);
        loop invariant (0 <= (remainder) && (remainder) <= (n));
        loop invariant (0 <= (count) && (count) <= (n) / (1));
        loop invariant ((n) == (remainder) + (count) * (1) + (quotient));
        loop invariant (0 <= (quotient) && (quotient) <= (n) - (remainder));
        loop assigns count, remainder;
    */
    while (remainder >= 1)
    {
        //@ assert remainder >= 1;
        count += 1;
        remainder -= 1;
        //@ assert (0 <= (remainder) && (remainder) <= (n));
        //@ assert ((n) == (remainder) + (count) * (1) + (quotient));
    }

    quotient += count * 1;
    remainder = n - quotient;

    result = quotient + remainder;
    //@ assert n == quotient + remainder;
    //@ assert result >= 0;
    //@ assert result <= n;

    return result;
}

int main()
{
    return 0;
}
