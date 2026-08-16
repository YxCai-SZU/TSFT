#include <stdint.h>

/*@ requires
        (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
    ensures
        \result == (((a) + (b)) * (h) / 2);
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t h)
{
    uint32_t sum;
    uint32_t product;
    uint32_t result;

    sum = a + b;
    //@ assert sum <= 200;
    
    product = sum * h;
    //@ assert product <= 20000;
    
    result = product / 2;
    //@ assert result == (a + b) * h / 2;
    
    return result;
}
