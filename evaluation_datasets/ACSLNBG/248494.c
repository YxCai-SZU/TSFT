#include <stdbool.h>


int func(int a, int b)
{
    int ans;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ans = a - b * 2;
    
    if (ans < 0)
    {
        //@ assert ((a) - (b) * 2) < 0;
        ans = 0;
    }
    
    //@ assert ((ans) >= 0);
    //@ assert ((ans) == (((a)) - ((b)) * 2) || (ans) == 0);
    return ans;
}
