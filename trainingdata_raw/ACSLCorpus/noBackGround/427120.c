#include <stdbool.h>

/*@
    requires a != b;
    requires ((a) == 1 || (a) == 2 || (a) == 3) && ((b) == 1 || (b) == 2 || (b) == 3);
    ensures ((\result) == 1 || (\result) == 2 || (\result) == 3);
    ensures \result != a && \result != b;
*/
int func(int a, int b)
{
    int ans;
    
    //@ assert a != b;
    ans = 6 - a - b;
    
    //@ assert ((ans) == 1 || (ans) == 2 || (ans) == 3);
    //@ assert ans != a && ans != b;
    
    return ans;
}
