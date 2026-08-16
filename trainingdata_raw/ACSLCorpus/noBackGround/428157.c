#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 1000000000);
    ensures \result == (((a) / 500) * 1000 + (((a) % 500) / 5) * 5);
    assigns \nothing;
*/
uint64_t func(uint64_t a)
{
    uint64_t res = 0;
    uint64_t c500;
    uint64_t c5;
    uint64_t local_a = a;

    //@ assert (0 <= (local_a) && (local_a) <= 1000000000);
    //@ assert local_a / 500 <= 1000000000;
    c500 = local_a / 500;
    res = res + c500 * 1000;
    local_a = local_a % 500;

    //@ assert 0 <= local_a && local_a < 500;
    //@ assert local_a / 5 <= 1000000000;
    c5 = local_a / 5;
    res = res + c5 * 5;
    local_a = local_a % 5;

    //@ assert res == (((a) / 500) * 1000 + (((a) % 500) / 5) * 5);
    return res;
}
