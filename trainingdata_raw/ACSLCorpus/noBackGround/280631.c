#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 20) && (1 <= (m) && (m) <= 20);
    ensures
        (1 <= n && n <= 9 && m >= 1 && \result == n * m) ||
        (n >= 10 && \result == -1);
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;
    
    //@ assert (1 <= (n) && (n) <= 20) && (1 <= (m) && (m) <= 20);
    
    if (1 <= n && n <= 9)
    {
        if (m >= 1)
        {
            //@ assert 1 <= n && n <= 9;
            //@ assert 1 <= m && m <= 20;
            //@ assert n * m <= 180;
            result = n * m;
        }
        else
        {
            result = -1;
        }
    }
    else
    {
        result = -1;
    }
    
    return result;
}
