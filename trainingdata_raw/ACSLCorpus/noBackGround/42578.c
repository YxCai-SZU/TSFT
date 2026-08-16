#include <limits.h>

/*@
    requires (2 <= (n) && (n) <= 100 &&
        2 <= (m) && (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int func(int n, int m)
{
    int n_unwrapped;
    int m_unwrapped;
    int result;

    //@ assert (2 <= (n) && (n) <= 100 &&         2 <= (m) && (m) <= 100);
    
    n_unwrapped = (n < 2) ? 2 : n;
    m_unwrapped = (m < 2) ? 2 : m;

    //@ assert n_unwrapped >= 2;
    //@ assert m_unwrapped >= 2;
    //@ assert n_unwrapped - 1 >= 1;
    //@ assert m_unwrapped - 1 >= 1;
    //@ assert (n_unwrapped - 1) * (m_unwrapped - 1) <= 99 * 99;

    result = (n_unwrapped - 1) * (m_unwrapped - 1);
    
    //@ assert result == (((n) - 1) * ((m) - 1));
    return result;
}
