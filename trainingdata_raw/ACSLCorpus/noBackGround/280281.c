/*@
    requires 0 <= h1 <= 23;
    requires 0 <= m1 <= 59;
    requires 0 <= h2 <= 23;
    requires 0 <= m2 <= 59;
    requires 0 <= k <= 100000;
    requires h1 <= h2;
    requires (h1 == h2 && m1 <= m2) || (h1 < h2);
    ensures \result == (h2 * 60 + m2 - h1 * 60 - m1 - k);
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int t1;
    int t2;
    int result;

    //@ assert (0 <= (h1) && (h1) <= 23 && 0 <= (m1) && (m1) <= 59);
    //@ assert (0 <= (h2) && (h2) <= 23 && 0 <= (m2) && (m2) <= 59);
    //@ assert ((h1) <= (h2) && ((h1) == (h2) ==> (m1) <= (m2)));

    t1 = 60 * h1 + m1;
    t2 = 60 * h2 + m2;

    //@ assert t1 == ((h1) * 60 + (m1));
    //@ assert t2 == ((h2) * 60 + (m2));
    //@ assert t1 <= t2;

    result = t2 - t1 - k;
    //@ assert result == (h2 * 60 + m2 - h1 * 60 - m1 - k);
    return result;
}
