/*@
    requires ((a) >= 0 && (a) <= 123 &&
        (b) >= 0 && (b) <= 123 &&
        (c) >= 0 && (c) <= 123 &&
        (d) >= 0 && (d) <= 123 &&
        (e) >= 0 && (e) <= 123 &&
        (k) >= 0 && (k) <= 123);
    ensures \result == 1 <==> ((((a)) + ((k))) >= (b) &&
        (((b)) + ((k))) >= (c) &&
        (((c)) + ((k))) >= (d) &&
        (((d)) + ((k))) >= (e));
    ensures \result == 0 <==> !((((a)) + ((k))) >= (b) &&
        (((b)) + ((k))) >= (c) &&
        (((c)) + ((k))) >= (d) &&
        (((d)) + ((k))) >= (e));
*/
int func(long long a, long long b, long long c, long long d, long long e, long long k)
{
    // Variable declarations at the top
    int result;

    //@ assert ((a) >= 0 && (a) <= 123 &&         (b) >= 0 && (b) <= 123 &&         (c) >= 0 && (c) <= 123 &&         (d) >= 0 && (d) <= 123 &&         (e) >= 0 && (e) <= 123 &&         (k) >= 0 && (k) <= 123);

    if (a + k < b)
    {
        //@ assert ((a) + (k)) < b;
        result = 0;
        return result;
    }

    if (b + k < c)
    {
        //@ assert ((b) + (k)) < c;
        result = 0;
        return result;
    }

    if (c + k < d)
    {
        //@ assert ((c) + (k)) < d;
        result = 0;
        return result;
    }

    if (d + k < e)
    {
        //@ assert ((d) + (k)) < e;
        result = 0;
        return result;
    }

    result = 1;
    //@ assert ((((a)) + ((k))) >= (b) &&         (((b)) + ((k))) >= (c) &&         (((c)) + ((k))) >= (d) &&         (((d)) + ((k))) >= (e));
    return result;
}
