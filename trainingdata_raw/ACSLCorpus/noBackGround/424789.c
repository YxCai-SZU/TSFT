/*@
    requires (0 <= (h1) && (h1) <= 23 && 0 <= (m1) && (m1) <= 59);
    requires (0 <= (h2) && (h2) <= 23 && 0 <= (m2) && (m2) <= 59);
    requires 0 <= k && k <= 23 * 60 + 59;
    requires ((h1) * 60 + (m1)) <= ((h2) * 60 + (m2));
    ensures \result == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int t1;
    int t2;
    int res;

    //@ assert (0 <= (h1) && (h1) <= 23 && 0 <= (m1) && (m1) <= 59);
    t1 = h1 * 60 + m1;
    //@ assert t1 == ((h1) * 60 + (m1));

    //@ assert (0 <= (h2) && (h2) <= 23 && 0 <= (m2) && (m2) <= 59);
    t2 = h2 * 60 + m2;
    //@ assert t2 == ((h2) * 60 + (m2));

    //@ assert t1 <= t2;
    res = t2 - t1 - k;
    //@ assert res == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;

    return res;
}
