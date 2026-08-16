/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures ((\result) >= 0 && (\result) <= (\old(n)) && ((\result) == (\old(n)) - (\old(m)) || (\result) == 0));
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int m)
{
    // Variable declarations at top of scope
    unsigned int n_local = n;
    unsigned int m_local = m;
    unsigned int res;

    if (n_local > m_local) {
        //@ assert n_local > m_local;
        n_local = n_local - m_local;
        //@ assert n_local == \at(n, Pre) - \at(m, Pre);
    } else {
        //@ assert n_local <= m_local;
        m_local = m_local - n_local;
        n_local = 0;
        //@ assert n_local == 0;
    }

    res = n_local;

    // Critical verification property
    //@ assert res >= 0 && res <= \at(n, Pre);

    return res;
}
