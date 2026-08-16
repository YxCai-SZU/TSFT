#include <stdint.h>

/*@
    requires ((a) >= 1 && (a) <= 100);
    ensures \result == a * (1 + a) / 2;
*/
uint32_t func(uint32_t a)
{
    uint32_t sum = 0;
    uint32_t i = 1;

    /*@
        loop invariant 1 <= i <= a + 1;
        loop invariant sum == (((i) - 1) * (i) / 2);
        loop invariant ((a) >= 1 && (a) <= 100);
        loop assigns sum, i;
        loop variant a - i + 1;
    */
    while (i <= a)
    {
        //@ assert 0 <= i * (i + 1) <= 100 * (100 + 1);
        //@ assert sum + i >= 0;
        //@ assert sum + i == i * (i + 1) / 2;
        //@ assert sum + i <= UINT32_MAX / 2;
        
        sum += i;
        i += 1;
        
        //@ assert sum == (((i) - 1) * (i) / 2);
    }
    
    return sum;
}
