#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result >= 0;
    ensures \result <= a || \result <= c;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int ans;
    
    if (b <= d)
    {
        if (a <= c)
        {
            ans = a;
        }
        else
        {
            ans = c;
        }
    }
    else
    {
        if (d <= a)
        {
            ans = d;
        }
        else
        {
            ans = a;
        }
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= a || ans <= c;
    
    return ans;
}
