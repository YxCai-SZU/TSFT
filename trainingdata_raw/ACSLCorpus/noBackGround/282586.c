#include <stdint.h>

/*@
    requires (1 <= (n) <= 5);
    ensures \result == ((n) * (n) * (n));
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at scope top
    int32_t result;

    //@ assert 1 <= n && n <= 5;
    //@ assert n * n <= 25;
    //@ assert n * n * n <= 125;

    result = (int32_t)n * (int32_t)n * (int32_t)n;
    return result;
}
