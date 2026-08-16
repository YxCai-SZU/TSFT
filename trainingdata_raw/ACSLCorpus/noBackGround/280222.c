#include <stdint.h>

/*@
    requires (0 <= (a) <= 100);
    requires (0 <= (b) <= 100);
    requires (0 <= (c) <= 100);
    ensures \result <= ((a) * (b) / 2 + (c));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    // Variable declarations at scope top
    uint32_t product;

    //@ assert (0 <= (a) <= 100);
    //@ assert (0 <= (b) <= 100);
    //@ assert (0 <= (c) <= 100);
    //@ assert ((a) * (b)) <= 10000;
    //@ assert ((a) * (b) / 2) <= 5000;

    product = a * b / 2 + c;
    //@ assert product == ((a) * (b) / 2 + (c));
    //@ assert product <= ((a) * (b) / 2 + (c));

    return product;
}
