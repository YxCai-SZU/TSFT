#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result == (((n) - 1) / 2 + 1);
    ensures \result <= n;
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert n - 1 >= 0;
    //@ assert (n - 1) / 2 <= 49999;
    //@ assert (n - 1) / 2 + 1 <= 50000;
    //@ assert (n - 1) / 2 + 1 <= n;
    //@ assert (n - 1) / 2 + 1 <= 4294967295;

    result = (n - 1) / 2 + 1;
    return result;
}
