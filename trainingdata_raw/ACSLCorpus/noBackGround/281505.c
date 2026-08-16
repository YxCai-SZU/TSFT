#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures \result == 0 || \result == n - m;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;
    
    if (n < m)
    {
        //@ assert n < m;
        result = 0;
    }
    else
    {
        //@ assert n >= m;
        result = n - m;
    }
    
    return result;
}
