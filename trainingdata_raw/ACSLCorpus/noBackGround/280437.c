/*@
    requires (2 <= (n) <= 100 && 2 <= (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int func(int n, int m)
{
    int n_copy;
    int m_copy;
    int result;

    //@ assert n > 1;
    //@ assert m > 1;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;

    n_copy = n - 1;
    m_copy = m - 1;

    //@ assert n_copy >= 1;
    //@ assert m_copy >= 1;
    //@ assert n_copy * m_copy <= 99 * 99;

    result = n_copy * m_copy;
    return result;
}
