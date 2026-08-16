#include <stdint.h>

/*@ predicate is_greater(integer n, integer m) = n > m; */

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> n > m;
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t ans;
    //@ assert 1 <= n <= 20;
    //@ assert 1 <= m <= 20;
    
    if (n > m) {
        ans = 1;
        //@ assert ans == 1;
    } else {
        ans = 0;
        //@ assert ans == 0;
    }
    
    //@ assert ans == 1 || ans == 0;
    //@ assert ans == 1 ==> n > m;
    return ans;
}
