#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures \result >= 0;
    ensures \result <= n;
    ensures \result == ((n) - (m) * 2 > 0 ? (n) - (m) * 2 : 0);
    assigns \nothing;
*/
int func(int n, int m)
{
    int result = 0;

    //@ assert (1 <= (n) <= 100 && 1 <= (m) <= 100);
    
    if (n - m * 2 > 0)
    {
        result = n - m * 2;
        //@ assert result == n - m * 2;
    }
    else
    {
        //@ assert result == 0;
    }

    //@ assert result == ((n) - (m) * 2 > 0 ? (n) - (m) * 2 : 0);
    return result;
}
