#include <limits.h>

/*@
    requires (1 <= (n) <= 20);
    requires (1 <= (m) <= 20);
    ensures \result >= 0;
    ensures \result == (n - 1) || \result == (m - 1) || 
            \result == (n - 1) * 2 || \result == (m - 1) * 2;
*/
int func(int n, int m)
{
    unsigned int n_unsigned;
    unsigned int m_unsigned;
    unsigned int min_val;
    unsigned int result;

    //@ assert (1 <= (n) <= 20);
    //@ assert (1 <= (m) <= 20);

    if (n < 0)
    {
        n_unsigned = (unsigned int)(-n);
    }
    else
    {
        n_unsigned = (unsigned int)n;
    }

    if (m < 0)
    {
        m_unsigned = (unsigned int)(-m);
    }
    else
    {
        m_unsigned = (unsigned int)m;
    }

    if (n_unsigned < m_unsigned)
    {
        min_val = n_unsigned;
    }
    else
    {
        min_val = m_unsigned;
    }

    //@ assert min_val >= 1 && min_val <= 20;
    result = (min_val - 1) * 2;

    if (n < 0 && m < 0)
    {
        //@ assert result == (((((((n)) < 0 ? -((n)) : ((n)))) < ((((m)) < 0 ? -((m)) : ((m)))) ? ((((n)) < 0 ? -((n)) : ((n)))) : ((((m)) < 0 ? -((m)) : ((m))))) - 1) * 2);
        return -(int)result;
    }
    else if (n < 0 || m < 0)
    {
        //@ assert result == (((((((n)) < 0 ? -((n)) : ((n)))) < ((((m)) < 0 ? -((m)) : ((m)))) ? ((((n)) < 0 ? -((n)) : ((n)))) : ((((m)) < 0 ? -((m)) : ((m))))) - 1) * 2);
        return (int)result - 1;
    }
    else
    {
        //@ assert result == (((((((n)) < 0 ? -((n)) : ((n)))) < ((((m)) < 0 ? -((m)) : ((m)))) ? ((((n)) < 0 ? -((n)) : ((n)))) : ((((m)) < 0 ? -((m)) : ((m))))) - 1) * 2);
        return (int)result;
    }
}
