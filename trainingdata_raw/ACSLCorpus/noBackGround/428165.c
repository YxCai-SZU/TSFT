#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t h)
{
    uint64_t sum;
    uint64_t res;

    //@ assert (1 <= (a) <= 100 &&         1 <= (b) <= 100 &&         1 <= (h) <= 100 &&         (h) % 2 == 0);
    sum = a + b;
    //@ assert sum == a + b;
    //@ assert sum * h <= 20000;
    res = sum * h / 2;
    //@ assert res == (((a) + (b)) * (h) / 2);
    return res;
}
