#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (h) && (h) <= 100 &&
        (h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t h)
{
    uint64_t base;
    uint64_t height;
    uint64_t area;

    base = a + b;
    //@ assert 1 <= base <= 200;

    height = h;

    //@ assert base * height <= 20000;

    area = base * height / 2;
    return area;
}
