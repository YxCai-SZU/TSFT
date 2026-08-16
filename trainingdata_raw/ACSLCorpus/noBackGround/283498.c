/*@
    requires (0 <= (x) && (x) <= 1000000000);
    ensures (((x) <= 5 && (\result) == 0) || ((x) > 5 && (\result) == (x) - 5));
*/
long func(long x)
{
    long ret;

    //@ assert (0 <= (x) && (x) <= 1000000000);

    if (x <= 5)
    {
        ret = 0;
        //@ assert ret == 0;
    }
    else
    {
        ret = x - 5;
        //@ assert ret == x - 5;
    }

    //@ assert (((x) <= 5 && (ret) == 0) || ((x) > 5 && (ret) == (x) - 5));
    return ret;
}
