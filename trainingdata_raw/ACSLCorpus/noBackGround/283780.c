#include <stdint.h>

/*@
    requires ((x) <= 1000000000);
    ensures \result == ((((x)) / 500) * 1000 + ((((x)) % 500) / 5) * 5);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t x_500;
    uint64_t x_5;
    uint64_t ans;

    x_500 = x / 500;
    x_5 = (x % 500) / 5;
    ans = x_500 * 1000 + x_5 * 5;

    //@ assert x_500 <= 2000000;
    //@ assert x_5 <= 100;
    //@ assert x_500 * 1000 <= 2000000000;
    //@ assert x_5 * 5 <= 500;
    //@ assert ans == ((((x)) / 500) * 1000 + ((((x)) % 500) / 5) * 5);

    return ans;
}
