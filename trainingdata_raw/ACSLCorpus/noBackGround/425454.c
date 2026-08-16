#include <stdbool.h>

/*@
    requires (1 <= (b) <= (a) <= 20 && 1 <= (c) <= 20);
    ensures \result >= 0 && \result <= c;
    ensures a - b >= c ==> \result == 0;
    ensures a - b < c ==> \result == c - (a - b);
*/
int func(int a, int b, int c)
{
    int ans = 0;
    
    //@ assert a - b >= 0;
    
    if (a - b < c)
    {
        //@ assert c - (a - b) >= 0;
        //@ assert c - (a - b) <= c;
        ans = c - (a - b);
    }
    
    //@ assert ans == ((a) - (b) >= (c) ? 0 : (c) - ((a) - (b)));
    return ans;
}
