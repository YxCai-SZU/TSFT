#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= (n) && (m) <= 5);
    ensures \result == ((integer)(n) - (integer)(m) + 1);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t result;
    uint32_t i;

    result = (int32_t)n - (int32_t)m + 1;
    i = 1;

    /*@
        loop invariant 1 <= i <= m;
        loop invariant result == ((integer)(n) - (integer)(m) + 1);
        loop assigns i;
    */
    while (i < m)
    {
        //@ assert i < m && i >= 1;
        i = i + 1;
    }

    //@ assert result == ((integer)(n) - (integer)(m) + 1);
    return result;
}
