#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
    ensures \result == (((h) * ((a) + (b))) / 2);
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t h)
{
    int32_t sum;
    int32_t product;
    uint32_t half;

    //@ assert (1 <= (a) <= 100 &&         1 <= (b) <= 100 &&         1 <= (h) <= 100 &&         (h) % 2 == 0);
    sum = a + b;
    //@ assert 1 <= a + b <= 200;
    product = h * sum;
    //@ assert 1 <= h * (a + b) <= 20000;
    half = ((uint32_t)product) / 2;
    return (int32_t)half;
}
