#include <stdint.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> ((n) % 2 == 0);
    ensures \result == 0 ==> ((n) % 2 == 1);
*/
int32_t func(uint64_t n)
{
    int32_t ans;
    //@ assert 1 <= n <= 100;
    
    if (n % 2 == 0)
    {
        ans = 1;
        //@ assert ((n) % 2 == 0);
    }
    else
    {
        ans = 0;
        //@ assert ((n) % 2 == 1);
    }
    
    //@ assert ans == 0 || ans == 1;
    return ans;
}
