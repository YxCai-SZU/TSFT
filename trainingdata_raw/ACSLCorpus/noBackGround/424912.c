#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) * (b) * 1000 + 99) / 100);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t product;
    uint32_t result;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    
    //@ assert 1 <= a * b <= 10000;
    product = a * b;
    
    //@ assert product * 1000 <= 10000 * 1000;
    result = product * 1000 + 99;
    result = result / 100;
    
    //@ assert result == (((a) * (b) * 1000 + 99) / 100);
    return (int32_t)result;
}
