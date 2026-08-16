#include <stdbool.h>

/*@
    requires (1 <= (n) <= 1000 && 1 <= (m) <= 1000 && 0 <= (k) <= (n) * (m));
    ensures \result == (n * m == k + (n * m - k));
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m, unsigned int k)
{
    long long n_ll, m_ll, k_ll;
    bool result;

    n_ll = (long long)n;
    m_ll = (long long)m;
    k_ll = (long long)k;

    //@ assert 1 <= n_ll <= 1000;
    //@ assert 1 <= m_ll <= 1000;
    //@ assert 0 <= k_ll <= n_ll * m_ll;
    //@ assert n_ll * m_ll <= 1000000;

    if (n_ll * m_ll == k_ll + (n_ll * m_ll - k_ll))
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == (n_ll * m_ll == k_ll + (n_ll * m_ll - k_ll));
    return result;
}
