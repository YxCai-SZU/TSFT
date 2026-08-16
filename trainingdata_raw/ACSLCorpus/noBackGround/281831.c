#include <stdint.h>

/*@
    requires (-1000000000 <= (x) <= 1000000000) && (-1000000000 <= (y) <= 1000000000);
    ensures \result >= 0;
    ensures (x + y == 0) ==> (\result == 0);
    ensures (x + y > 0) ==> (\result == x + y);
*/
int64_t func(int64_t x, int64_t y)
{
    int64_t ans;
    //@ assert (-1000000000 <= (x) <= 1000000000) && (-1000000000 <= (y) <= 1000000000);
    
    if (x + y > 0)
    {
        ans = x + y;
        //@ assert ans == x + y;
    }
    else
    {
        ans = 0;
        //@ assert ans == 0;
    }
    
    //@ assert ans >= 0;
    //@ assert (x + y == 0) ==> (ans == 0);
    //@ assert (x + y > 0) ==> (ans == x + y);
    
    return ans;
}
