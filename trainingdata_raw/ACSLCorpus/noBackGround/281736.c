#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 100000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t res;
    uint32_t temp_x;
    uint32_t n_500;
    uint32_t n_5;

    res = 0;
    temp_x = x;

    n_500 = x / 500;
    //@ assert n_500 == x / 500;
    res = res + n_500 * 1000;
    //@ assert res == (x / 500) * 1000;
    temp_x = temp_x - n_500 * 500;
    //@ assert temp_x == x % 500;

    n_5 = temp_x / 5;
    //@ assert n_5 == (x % 500) / 5;
    res = res + n_5 * 5;
    //@ assert res == (x / 500) * 1000 + ((x % 500) / 5) * 5;
    temp_x = temp_x - n_5 * 5;
    //@ assert temp_x == (x % 500) % 5;

    return res;
}
