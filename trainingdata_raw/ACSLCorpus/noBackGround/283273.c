#include <stdbool.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;
    ans = c - (a - b);
    
    if (ans < 0)
    {
        //@ assert ans < 0;
        return 0;
    }
    else
    {
        //@ assert ans >= 0;
        //@ assert ans <= c;
        return ans;
    }
}
