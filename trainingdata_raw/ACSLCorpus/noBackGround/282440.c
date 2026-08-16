/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= (n) &&
        (m) <= 5);
    ensures \result == (1000 * ((n) - (m)) + 1900 * (m));
    assigns \nothing;
*/
int func(unsigned int n, unsigned int m)
{
    int res;
    int temp;
    unsigned int i;

    //@ assert (1 <= (n) <= 100 &&         1 <= (m) <= (n) &&         (m) <= 5);

    res = 0;
    temp = 1000 * ((int)n - (int)m);
    i = 0;

    /*@
        loop invariant 0 <= i <= m;
        loop invariant res == 1900 * (int)i;
        loop invariant temp == 1000 * ((int)n - (int)m);
        loop invariant (1 <= (n) <= 100 &&
        1 <= (m) <= (n) &&
        (m) <= 5);
        loop assigns res, i;
        loop variant m - i;
    */
    while (i < m)
    {
        //@ assert i < m;
        res += 1900;
        i += 1;
        //@ assert res == 1900 * (int)i;
    }

    //@ assert i == m;
    //@ assert res == 1900 * (int)m;

    res += temp;

    //@ assert res == (1000 * ((n) - (m)) + 1900 * (m));
    return res;
}
