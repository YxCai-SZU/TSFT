#include <stdbool.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100);
    ensures \result >= 0;
    ensures \result == A - 2 * B || \result == 0;
    assigns \nothing;
*/
int func(int A, int B)
{
    int ans;
    int res;

    ans = A - 2 * B;
    //@ assert ans >= 0 || ans == A - 2 * B;
    
    if (ans > 0)
    {
        res = ans;
    }
    else
    {
        res = 0;
    }
    
    return res;
}
