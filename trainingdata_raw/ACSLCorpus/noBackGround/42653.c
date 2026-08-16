#include <stdint.h>

/*@
    requires (1 <= (k) <= (n) <= 50);
    ensures \result == n - k + 1;
*/
uint64_t func(uint64_t n, uint64_t k)
{
    uint64_t result;
    uint64_t i;

    result = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= k;
        loop invariant result == 0;
        loop assigns i;
        loop variant k - i;
    */
    while (i < k)
    {
        i = i + 1;
    }

    //@ assert i == k;
    result = n - k + 1;
    //@ assert result == n - k + 1;
    
    return result;
}
