#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (h) && (h) <= 100 &&
        (h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t h)
{
    uint32_t sum;
    uint32_t result;

    //@ assert 2 <= a + b && a + b <= 200;
    sum = a + b;

    //@ assert 2 <= sum * h && sum * h <= 20000;
    result = sum * h / 2;

    return result;
}
