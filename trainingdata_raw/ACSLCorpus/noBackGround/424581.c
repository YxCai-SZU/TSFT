/*@
    requires (1 <= (n) && (n) <= 1000000000);
    ensures ((\result) % 2 == 0);
    ensures \result >= 2;
    ensures \result <= 2 * n;
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    unsigned int result;
    unsigned int i;
    unsigned int remainder;

    result = 0;
    if (n % 2 == 0)
    {
        result = n;
    }
    else
    {
        result = n * 2;
    }

    i = n;
    /*@
        loop invariant 1 <= i && i <= n;
        loop invariant ((result) % 2 == 0);
        loop invariant result >= 2;
        loop invariant result <= 2 * n;
        loop invariant i > 1 || result >= 2;
        loop assigns i, result, remainder;
        loop variant i;
    */
    while (i > 1)
    {
        remainder = n;
        /*@
            loop invariant remainder >= 0 && remainder <= n;
            loop assigns remainder;
            loop variant remainder;
        */
        while (remainder >= i)
        {
            remainder -= i;
        }

        if (remainder == 0)
        {
            result = i * 2;
            break;
        }
        i -= 1;
    }
    return result;
}
