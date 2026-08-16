#include <stdbool.h>

/*@
    requires 1 <= n && n <= 100;
    requires 1 <= m && m <= 100;
    ensures \result == ((n * 2) <= m && m % 2 == 0);
*/
bool func(int n, int m)
{
    int n_copy;
    int m_copy;
    bool result;

    n_copy = n;
    m_copy = m;

    //@ assert n_copy == n && m_copy == m;

    if (n * 2 <= m)
    {
        if (m % 2 == 0)
        {
            //@ assert (n * 2) <= m && m % 2 == 0;
            result = true;
        }
        else
        {
            //@ assert !((n * 2) <= m && m % 2 == 0);
            result = false;
        }
    }
    else
    {
        //@ assert !((n * 2) <= m && m % 2 == 0);
        result = false;
    }

    //@ assert result == ((n * 2) <= m && m % 2 == 0);
    return result;
}
