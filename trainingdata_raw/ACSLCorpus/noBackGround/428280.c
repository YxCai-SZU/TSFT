/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) &&
        1 <= (k) && (k) <= (a) + (b) + (c) && (k) <= 2000000000);
    ensures \result >= -c;
    ensures \result <= a;
    ensures \result == (((a) >= (k)) ? (k) : (a) - (((k) - (a) - (b) - (c) > 0) ? (k) - (a) - (b) - (c) : 0));
*/
long func(long a, long b, long c, long k)
{
    long res;
    long rst;
    long tmp1;
    long tmp2;
    long tmp3;

    res = 0;
    rst = k;

    if (a >= rst)
    {
        res = res + rst;
    }
    else
    {
        res = res + a;
    }

    tmp1 = rst - a;
    if (tmp1 > 0)
    {
        rst = tmp1;
    }
    else
    {
        rst = 0;
    }

    tmp2 = rst - b;
    if (tmp2 > 0)
    {
        rst = tmp2;
    }
    else
    {
        rst = 0;
    }

    tmp3 = rst - c;
    if (tmp3 > 0)
    {
        res = res - tmp3;
    }
    else
    {
        res = res - 0;
    }

    //@ assert res == (((a) >= (k)) ? (k) : (a) - (((k) - (a) - (b) - (c) > 0) ? (k) - (a) - (b) - (c) : 0));
    return res;
}
