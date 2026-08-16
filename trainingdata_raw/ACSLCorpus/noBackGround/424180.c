#include <stdint.h>
/*@
    requires 1 <= n && n <= 100;
    ensures \result == n * n;
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    //@ assert 1 <= n && n <= 100;
    //@ assert n * n <= 10000;
    return n * n;
}
