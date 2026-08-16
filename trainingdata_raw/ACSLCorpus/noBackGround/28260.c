#include <limits.h>

/*@
    requires (2 <= (n) && (n) <= 100) && (2 <= (m) && (m) <= 100);
    ensures \result == (n - 1) * (m - 1);
    assigns \nothing;
*/
int func(int n, int m)
{
    unsigned int n_unsigned;
    unsigned int m_unsigned;
    unsigned int result_unsigned;
    int result;

    n_unsigned = (n < 0) ? (unsigned int)(-n) : (unsigned int)n;
    m_unsigned = (m < 0) ? (unsigned int)(-m) : (unsigned int)m;

    //@ assert n_unsigned > 1 && n_unsigned <= 100;
    //@ assert m_unsigned > 1 && m_unsigned <= 100;
    //@ assert (n_unsigned - 1) * (m_unsigned - 1) <= 99 * 99;

    result_unsigned = (n_unsigned - 1) * (m_unsigned - 1);

    if ((n < 0 && m < 0) || (n >= 0 && m >= 0))
    {
        result = (int)result_unsigned;
    }
    else
    {
        result = -(int)result_unsigned;
    }

    return result;
}
