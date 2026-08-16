#include <stdint.h>

/*@
    requires (0 <= (n) < 0x80000000);
    ensures \result == (2 * (n));
    assigns \nothing;
*/
uint32_t count_first_n_odd(uint32_t n)
{
    uint32_t count;
    uint32_t i;
    
    count = 0;
    i = 0;
    
    /*@
        loop invariant i <= n;
        loop invariant count == 2 * i;
        loop invariant (0 <= (n) < 0x80000000);
        loop assigns count, i;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert count == 2 * i;
        count += 2;
        i += 1;
    }
    
    return count;
}
