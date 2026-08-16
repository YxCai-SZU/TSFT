/*@
    requires 1 <= n <= 100;
    requires 0 <= m <= n;
    ensures \result == (n == m);
*/
_Bool func(int n, int m)
{
    // Variable declarations at scope top
    int i;

    i = 0;
    /*@
        loop invariant 0 <= i <= 1;
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= m <= n;
        loop assigns i;
    */
    while (i < 1)
    {
        i += 1;
    }

    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= m && m <= n;
    //@ assert n >= m;
    //@ assert n - m <= 100;

    return n == m;
}

int main(void)
{
    return 0;
}
