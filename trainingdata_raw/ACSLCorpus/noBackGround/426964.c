/*@
    requires ((0) <= (a) && (a) <= (100)) && ((0) <= (p) && (p) <= (100));
    ensures ((\result) >= 0);
    ensures \result <= ((a) * 3 + (p));
*/
long func(long a, long p)
{
    long sum;
    long pies;
    int is_negative;

    sum = a * 3 + p;
    pies = 0;
    is_negative = 0;

    //@ assert sum == ((a) * 3 + (p));
    if (sum < 0)
    {
        sum = -sum;
        is_negative = 1;
    }

    /*@
        loop invariant ((sum) >= 0);
        loop invariant sum <= ((a) * 3 + (p));
        loop invariant ((pies) >= 0);
        loop invariant ((0) <= (a) && (a) <= (100));
        loop invariant ((0) <= (p) && (p) <= (100));
        loop invariant sum + 2 * pies == ((a) * 3 + (p));
        loop assigns sum, pies;
        loop variant sum;
    */
    while (sum >= 2)
    {
        //@ assert sum >= 2;
        sum -= 2;
        pies += 1;
        //@ assert sum + 2 * pies == ((a) * 3 + (p));
    }

    if (is_negative)
    {
        pies = -pies;
    }

    //@ assert pies <= ((a) * 3 + (p));
    return pies;
}
