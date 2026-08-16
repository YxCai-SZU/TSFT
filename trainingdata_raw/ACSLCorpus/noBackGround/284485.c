#include <limits.h>

/*@
    requires (1 <= (n) <= 20);
    requires (1 <= (m) <= 20);
    ensures \result >= 1;
    ensures \result <= 40;
    ensures \result == (2 * (n)) || 
            \result == (2 * (m)) || 
            \result == (2 * (n) - 1) || 
            \result == (2 * (m) - 1);
    assigns \nothing;
*/
int func(int n, int m)
{
    int res;
    
    if (n == m)
    {
        res = 2 * n;
    }
    else
    {
        if (n > m)
        {
            res = 2 * n - 1;
        }
        else
        {
            res = 2 * m - 1;
        }
    }
    
    //@ assert res >= 1 && res <= 40;
    //@ assert res == (2 * (n)) || res == (2 * (m)) || res == (2 * (n) - 1) || res == (2 * (m) - 1);
    
    return res;
}
