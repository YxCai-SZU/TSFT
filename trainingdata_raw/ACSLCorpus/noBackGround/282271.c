#include <stdint.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t c500;
    uint32_t r500;
    uint32_t c5;
    uint32_t r5;
    uint32_t res;

    c500 = x / 500;
    r500 = x % 500;
    c5 = r500 / 5;
    r5 = r500 % 5;
    res = c500 * 1000 + c5 * 5;

    //@ assert c500 * 1000 == (x / 500) * 1000;
    //@ assert c5 * 5 == (r500 / 5) * 5;
    //@ assert res == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);

    return res;
}

/*@
    requires (0 <= (x) <= 1000000000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    assigns \nothing;
*/
uint32_t func_v2(uint32_t x)
{
    uint32_t c500;
    uint32_t r500;
    uint32_t c5;
    uint32_t r5;
    uint32_t res;

    c500 = x / 500;
    r500 = x % 500;
    c5 = r500 / 5;
    r5 = r500 % 5;

    //@ assert c500 * 1000 == (x / 500) * 1000;
    //@ assert c5 * 5 == (r500 / 5) * 5;
    //@ assert c500 * 1000 + c5 * 5 == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);

    res = c500 * 1000 + c5 * 5;
    return res;
}
