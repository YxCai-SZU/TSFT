#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result >= 0 && \result <= n;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at top
    uint32_t max = 0;
    uint32_t count = 0;
    uint32_t i = 1;
    
    //@ assert 1 <= n && n <= 100000;
    
    /*@
        loop invariant 1 <= i && i <= n + 1;
        loop invariant 0 <= max && max <= n;
        loop invariant 0 <= count && count <= i;
        loop invariant count <= n;
        loop assigns i, max, count;
    */
    while (i <= n) {
        uint32_t current = n / i;
        
        if (max <= current) {
            max = current;
            count = 1;
        } else if (max == current) {
            count += 1;
        }
        
        i += 1;
    }
    
    //@ assert count <= n;
    return (int32_t)count;
}
