#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (((a) * (b)) * ((a) * (b)));
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Declare all variables at the top
    uint32_t product;
    int32_t result;

    //@ assert a <= 100;
    //@ assert b <= 100;

    product = a * b;
    //@ assert product <= 10000;

    result = (int32_t)product * (int32_t)product;
    //@ assert result <= 100000000;
    //@ assert result >= 0;

    return result;
}
