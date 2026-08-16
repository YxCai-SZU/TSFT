#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 100) && (1 <= (B) && (B) <= 100);
    ensures \result == (((A) * (B)) / 2);
    assigns \nothing;
*/
int32_t func(uint32_t A, uint32_t B)
{
    uint32_t product;
    uint32_t half_product;
    int32_t result;

    //@ assert A * B <= 10000;
    product = A * B;
    half_product = product / 2;
    result = (int32_t)half_product;
    return result;
}
