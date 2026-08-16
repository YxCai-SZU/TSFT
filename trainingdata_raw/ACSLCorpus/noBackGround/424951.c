#include <stdint.h>

/*@
    requires ((n) <= 0xffff);
    ensures \result == ((n) * (n));
    ensures \result == (uint32_t)((uint64_t)n * (uint64_t)n);
    assigns \nothing;
*/
uint32_t square_number(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert ((n) <= 0xffff);
    //@ assert ((n) * (n)) <= 0xffff * 0xffff;

    result = n * n;

    //@ assert result == ((n) * (n));
    //@ assert result == (uint32_t)((uint64_t)n * (uint64_t)n);

    return result;
}
