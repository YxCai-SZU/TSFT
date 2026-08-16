#include <stdint.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20) && (1 <= (t) <= 20);
    ensures \result == ((b) * ((t) / (a)));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t t)
{
    uint32_t quotient;
    uint32_t product;

    //@ assert 1 <= a && a <= 20;
    //@ assert 1 <= b && b <= 20;
    //@ assert 1 <= t && t <= 20;

    quotient = t / a;

    //@ assert quotient <= 20;
    //@ assert b * quotient <= 400;

    product = b * quotient;

    //@ assert product == ((b) * ((t) / (a)));

    return product;
}
