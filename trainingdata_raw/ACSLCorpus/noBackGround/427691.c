#include <stdint.h>

/*@
    requires 1 <= N <= 100;
    ensures \result == (N + 1) / 2;
*/
uint32_t func(uint32_t N)
{
    uint32_t ans;
    uint32_t count;
    
    ans = N + 1;
    count = 0;
    
    /*@
        loop invariant (0 <= (ans) <= (N) + 1);
        loop invariant (0 <= (count) <= ((N) + 1) / 2);
        loop invariant ((ans) == (N) + 1 - 2 * (count));
        loop assigns ans, count;
        loop variant ans;
    */
    while (ans > 1)
    {
        //@ assert ans > 1;
        ans -= 2;
        count += 1;
    }
    
    //@ assert count == (N + 1) / 2;
    return count;
}
