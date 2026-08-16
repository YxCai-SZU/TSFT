#include <stdbool.h>
#include <stdint.h>

/*@
    requires 2 <= x <= 1000000;
    ensures \result <= 0xFFFFFFFF / 2;
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t count;
    uint32_t n;
    
    count = 0;
    n = 1;
    
    /*@
        loop invariant 1 <= n <= x;
        loop invariant count <= n - 1;
        loop invariant 2 <= x <= 1000000;
        loop assigns count, n;
        loop variant x - n;
    */
    while (n < x)
    {
        //@ assert n < x;
        
        if ((n & 1) == 0)
        {
            count += 1;
        }
        
        n += 1;
    }
    
    //@ assert count <= 0xFFFFFFFF / 2;
    return count;
}
