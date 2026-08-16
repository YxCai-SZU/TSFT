#include <stdbool.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures \result >= 0;
    ensures \result <= n;
    ensures \result == 0 || \result == 1 || \result == n - m;
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;
    
    //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20);
    
    if (n > m)
    {
        result = n - m;
    }
    else
    {
        result = 0;
    }
    
    //@ assert result >= 0 && result <= n;
    //@ assert result == 0 || result == 1 || result == n - m;
    
    return result;
}
