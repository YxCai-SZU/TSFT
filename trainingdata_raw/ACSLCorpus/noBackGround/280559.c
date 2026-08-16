/*@
    requires (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    ensures \result == (s * t >= d);
*/
int func(long d, long t, long s)
{
    // Variable declarations at scope top
    long x;

    //@ assert 1 <= s * t <= 10000 * 10000;
    x = s * t;

    if (x < 0)
    {
        //@ assert x >= 1;
        return 0;
    }
    else
    {
        //@ assert x <= 10000 * 10000;
        return x >= d;
    }
}
