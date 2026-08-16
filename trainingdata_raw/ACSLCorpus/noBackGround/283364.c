/*@
    requires ((h1) >= 0 && (h1) < 24 && (m1) >= 0 && (m1) < 60);
    requires ((h2) >= 0 && (h2) < 24 && (m2) >= 0 && (m2) < 60);
    requires k >= 0 && k < 1440;
    requires ((h2) * 60 + (m2) - (h1) * 60 - (m1) >= (k));
    ensures \result >= 0;
    ensures \result <= 1440;
    ensures \result == h2 * 60 + m2 - h1 * 60 - m1 - k;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int t1;
    int t2;
    int x;

    t1 = h1 * 60 + m1;
    t2 = h2 * 60 + m2;
    x = t2 - t1 - k;

    //@ assert x >= 0;
    //@ assert x <= 1440;
    //@ assert x == h2 * 60 + m2 - h1 * 60 - m1 - k;

    return x;
}
