#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= 100 &&
        1 <= (i) <= (n) &&
        1 <= (j) <= (m) &&
        (i) <= (n) - 1 &&
        (j) <= (m) - 1);
    ensures \result == (((n) - 1) * ((m) - 1) - ((i) - 1) * ((m) - 1) - ((j) - 1) * ((n) - 1) + 1);
    assigns \nothing;
*/
int func(int n, int m, int i, int j)
{
    int n_minus_1;
    int m_minus_1;
    int i_minus_1;
    int j_minus_1;
    int result;

    n_minus_1 = n - 1;
    m_minus_1 = m - 1;
    i_minus_1 = i - 1;
    j_minus_1 = j - 1;

    //@ assert 0 <= n_minus_1 * m_minus_1 <= 99 * 99;
    //@ assert 0 <= i_minus_1 * m_minus_1 <= 99 * 99;
    //@ assert 0 <= j_minus_1 * n_minus_1 <= 99 * 99;

    result = n_minus_1 * m_minus_1 - i_minus_1 * m_minus_1 - j_minus_1 * n_minus_1 + 1;
    return result;
}
