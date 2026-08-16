#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == a - 2 * b || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int ans;
    int result;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    ans = a - 2 * b;
    
    if (ans < 0)
    {
        result = 0;
    }
    else
    {
        //@ assert ans >= 0;
        result = ans;
    }
    
    //@ assert result >= 0;
    return result;
}
