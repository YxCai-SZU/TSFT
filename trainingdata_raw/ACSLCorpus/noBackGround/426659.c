#include <limits.h>

/*@
    requires (2 <= (n) <= 100 && 2 <= (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int read(int n, int m)
{
    int result;
    int n_minus_1;
    int m_minus_1;

    //@ assert (2 <= (n) <= 100 && 2 <= (m) <= 100);
    //@ assert 1 <= n - 1 <= 99;
    //@ assert 1 <= m - 1 <= 99;
    //@ assert (n - 1) * (m - 1) <= 9801;

    n_minus_1 = n - 1;
    m_minus_1 = m - 1;
    result = n_minus_1 * m_minus_1;

    //@ assert result == (((n) - 1) * ((m) - 1));
    return result;
}
