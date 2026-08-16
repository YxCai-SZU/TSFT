/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (k) >= 1 && (k) <= (a) + (b) + (c));
    ensures \result <= k;
    ensures \result == ((k) <= (a) ? (k) : ((k) <= (a) + (b) ? (a) : (a) - ((k) - (a) - (b))));
*/
long func(long a, long b, long c, long k)
{
    long result;
    long remaining;

    result = 0;
    remaining = k;

    if (a >= remaining)
    {
        result += remaining;
        remaining = 0;
    }
    else
    {
        result += a;
        remaining -= a;
    }

    if (b >= remaining)
    {
        remaining = 0;
    }
    else
    {
        remaining -= b;
    }

    result -= remaining;

    //@ assert result == ((k) <= (a) ? (k) : ((k) <= (a) + (b) ? (a) : (a) - ((k) - (a) - (b))));
    //@ assert result <= k;

    return result;
}
