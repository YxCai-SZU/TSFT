#include <stdint.h>

/*@
    requires -100 <= a <= 100;
    ensures \result == ((a) >= 0 ? (a) : 0);
    ensures ((a) >= 0) ==> \result == a;
    ensures ((a) < 0) ==> \result == 0;
*/
int64_t func(int64_t a)
{
    int64_t ans;
    
    if (a >= 0)
    {
        ans = a;
        //@ assert ans == a;
    }
    else
    {
        ans = 0;
        //@ assert ans == 0;
    }
    
    return ans;
}
