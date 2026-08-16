/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= (n) && (m) <= 5);
    ensures \result >= (100 * ((n) - (m)) + 1900 * (m));
    ensures \result <= (1900 * (n));
*/
int func(int n, int m) {
    int ans = 0;
    int i = 1;

    //@ ghost int m_local = m;
    //@ ghost int n_local = n;

    /*@
        loop invariant 1 <= i <= m_local + 1;
        loop invariant ans == 1900 * (i - 1);
        loop invariant (1 <= (n_local) <= 100 && 1 <= (m_local) <= (n_local) && (m_local) <= 5);
        loop assigns ans, i;
        loop variant m_local - i + 1;
    */
    while (i <= m) {
        //@ assert ans + 1900 == 1900 * i;
        ans += 1900;
        i += 1;
    }

    i = 1;

    /*@
        loop invariant 1 <= i <= n_local - m_local + 1;
        loop invariant ans == 1900 * m_local + 100 * (i - 1);
        loop invariant (1 <= (n_local) <= 100 && 1 <= (m_local) <= (n_local) && (m_local) <= 5);
        loop assigns ans, i;
        loop variant n_local - m_local - i + 1;
    */
    while (i <= n - m) {
        //@ assert ans + 100 == 1900 * m_local + 100 * i;
        ans += 100;
        i += 1;
    }

    //@ assert ans >= (100 * ((n_local) - (m_local)) + 1900 * (m_local));
    //@ assert ans <= (1900 * (n_local));
    return ans;
}
