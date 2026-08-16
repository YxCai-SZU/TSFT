/*@
    requires (1 <= (a) && (a) <= 1000);
    requires (1 <= (b) && (b) <= 1000);
    requires ((a) + (b) <= (x) && (x) <= 10000);
    requires x % 1 == 0;
    requires a % 1 == 0;
    requires b % 1 == 0;
    ensures ((\result) >= 0 && (\result) <= (a) + (b));
*/
long func(long x, long a, long b)
{
    long result;
    long diff;

    result = a;
    //@ assert ((result) >= 0 && (result) <= (a) + (b));
    if (a < x)
    {
        diff = x - a;
        //@ assert diff >= 0;
        if (diff < b)
        {
            result += diff;
        }
        else
        {
            result += b;
        }
        //@ assert ((result) >= 0 && (result) <= (a) + (b));
    }
    //@ assert ((result) >= 0 && (result) <= (a) + (b));
    return result;
}
