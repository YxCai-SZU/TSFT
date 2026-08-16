#include <stdint.h>

/*@
    requires ((n) > 0 && (n) <= 100);
    ensures \result == ((n) * (n) * (n));
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert ((n) > 0 && (n) <= 100);
    //@ assert n * n <= 10000;
    //@ assert n * n * n <= 1000000;

    result = n * n * n;
    return result;
}
