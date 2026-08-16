#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t h)
{
    // Variable declarations at scope top
    uint32_t sum;
    uint32_t product;
    uint32_t area;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= h <= 100;
    //@ assert h % 2 == 0;

    // Verify addition doesn't overflow
    //@ assert a + b <= 200;

    sum = a + b;
    //@ assert sum <= 200;

    // Verify multiplication doesn't overflow
    //@ assert sum * h <= 20000;

    product = sum * h;
    //@ assert product <= 20000;

    // Verify division doesn't overflow
    //@ assert product / 2 <= 10000;

    area = product / 2;
    //@ assert area == (a + b) * h / 2;

    return area;
}
