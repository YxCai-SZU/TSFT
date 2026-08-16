#include <stdint.h>
/*@
    requires (1 <= (x) && (x) <= 100) && (1 <= (y) && (y) <= 100) && (1 <= (z) && (z) <= 100);
    ensures \result == (x * y) / 2;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z)
{
    // Variable declarations
    uint32_t product;
    uint32_t half_product;

    //@ assert (1 <= (x) && (x) <= 100);
    //@ assert (1 <= (y) && (y) <= 100);
    //@ assert x * y <= 10000;
    product = x * y;
    //@ assert product <= 10000;
    half_product = product / 2;
    //@ assert half_product * 2 <= product;
    return half_product;
}

/*@
    assigns \nothing;
*/
int main()
{
    // Variable declarations
    uint32_t x;
    uint32_t y;
    uint32_t z;
    uint32_t result;

    x = 10;
    y = 20;
    z = 30;
    //@ assert (1 <= (x) && (x) <= 100) && (1 <= (y) && (y) <= 100) && (1 <= (z) && (z) <= 100);
    result = func(x, y, z);
    //@ assert result == 100;
    return 0;
}
