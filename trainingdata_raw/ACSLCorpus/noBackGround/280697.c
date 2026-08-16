#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (k) <= 100);
    ensures \result == 0 || \result == 1;
*/
int32_t func(uint32_t n, uint32_t k)
{
    // Variable declarations at scope top
    int32_t x = 0;
    uint32_t i = 0;
    int32_t result;

    //@ assert x >= 0 && x < (int32_t)k;
    //@ assert i == 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant x >= 0 && x < (int32_t)k;
        loop assigns x, i;
    */
    while (i < n) {
        //@ assert x >= 0 && x < (int32_t)k;
        x = (x + 1 < (int32_t)k) ? (x + 1) : 0;
        //@ assert x >= 0 && x < (int32_t)k;
        i++;
        //@ assert 0 <= i <= n;
    }

    //@ assert x >= 0 && x < (int32_t)k;
    if (x == 0) {
        result = 0;
        //@ assert result == 0;
    } else {
        result = 1;
        //@ assert result == 1;
    }
    
    return result;
}
