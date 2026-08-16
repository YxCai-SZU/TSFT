#include <stdint.h>

/*@
    requires (1 <= (n) <= 100000000000000000);
    ensures \result == ((n) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t res;
    //@ assert (1 <= (n) <= 100000000000000000);
    res = n / 2;
    //@ assert res == ((n) / 2);
    return res;
}
