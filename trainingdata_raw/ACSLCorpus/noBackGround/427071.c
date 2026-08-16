#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == ((a) > (b) * 2 ? (a) - (b) * 2 : 0);
    assigns \nothing;
*/
int func(int a, int b)
{
    int res;
    int ans;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    res = a - b * 2;
    
    if (res > 0)
    {
        ans = res;
        //@ assert ans == a - b * 2;
    }
    else
    {
        ans = 0;
        //@ assert ans == 0;
    }
    
    //@ assert ans == ((a) > (b) * 2 ? (a) - (b) * 2 : 0);
    //@ assert ans >= 0;
    
    return ans;
}
