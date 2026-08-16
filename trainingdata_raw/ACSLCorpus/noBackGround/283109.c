#include <stdbool.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == ((c) < (a) - (b) + 1 ? 0 : (c) - ((a) - (b)));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int ans;
    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    
    ans = c - (a - b);
    
    if (ans < 0)
    {
        //@ assert ans < 0;
        ans = 0;
    }
    
    //@ assert ans >= 0 && ans <= c;
    //@ assert ans == ((c) < (a) - (b) + 1 ? 0 : (c) - ((a) - (b)));
    
    return ans;
}
