#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    ensures \result == n * n - a;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t a)
{
    // Variable declarations at top
    uint32_t result;

    //@ assert n <= 100;
    //@ assert a <= n * n;
    //@ assert 1 <= n;
    //@ assert 0 <= a;
    //@ assert n * n <= 10000;
    //@ assert n * n >= a;

    result = n * n - a;
    return result;
}
