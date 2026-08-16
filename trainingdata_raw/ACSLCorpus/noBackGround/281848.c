/*@
    requires (0 <= (n) && (n) <= 100 &&
        0 <= (m) && (m) <= 100 &&
        (n) >= 1 &&
        (m) >= 1);
    ensures \result <= ((n) + (m) / 2);
    ensures \result >= 0;
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int m)
{
    unsigned int result;
    unsigned int remaining;

    result = 0;
    remaining = n + m;

    if (remaining < 2)
    {
        //@ assert result <= ((n) + (m) / 2);
        return result;
    }

    remaining -= 2;
    result += 1;

    /*@
        loop invariant 0 <= result && result <= ((n) + (m) / 2);
        loop invariant 0 <= remaining && remaining <= n + m;
        loop invariant result <= (n + m - remaining) / 2;
        loop assigns remaining, result;
        loop variant remaining;
    */
    while (remaining >= 2)
    {
        //@ assert remaining >= 2;
        remaining -= 2;
        result += 1;
        //@ assert result <= (n + m - remaining) / 2;
    }

    //@ assert result <= ((n) + (m) / 2);
    return result;
}
