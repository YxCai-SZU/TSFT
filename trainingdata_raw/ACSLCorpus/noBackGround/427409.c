#include <limits.h>

/*@
    requires (400 <= (x) && (x) < 2000);
    ensures (1 <= (\result) && (\result) <= 8);
    ensures ((\result) == 1 ==> (1200 <= (x) && (x) < 2000));
    ensures ((\result) == 2 ==> (800 <= (x) && (x) < 1200));
    ensures ((\result) == 3 ==> (400 <= (x) && (x) < 800));
*/
int func(int x)
{
    int ans;
    
    //@ assert (400 <= (x) && (x) < 2000);
    
    if (x >= 1200 && x < 2000)
    {
        ans = 1;
    }
    else if (x >= 800 && x < 1200)
    {
        ans = 2;
    }
    else
    {
        ans = 3;
    }
    
    //@ assert (1 <= (ans) && (ans) <= 8);
    //@ assert ((ans) == 1 ==> (1200 <= (x) && (x) < 2000));
    //@ assert ((ans) == 2 ==> (800 <= (x) && (x) < 1200));
    //@ assert ((ans) == 3 ==> (400 <= (x) && (x) < 800));
    
    return ans;
}
