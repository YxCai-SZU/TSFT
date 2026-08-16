#include <stdint.h>

/*@
    requires (0 <= (n) && (n) <= 1000000000000000 &&
        0 <= (m) && (m) <= 1000000000000000);
    ensures \result >= 0;
    ensures \result <= m / 2;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t res;

    //@ assert (0 <= (n) && (n) <= 1000000000000000 &&         0 <= (m) && (m) <= 1000000000000000);

    if (n * 2 <= m) {
        res = n;
    } else {
        res = m / 2;
    }

    //@ assert res == (((n) * 2 <= (m)) ? (n) : (m) / 2);
    //@ assert res <= m / 2;

    return res;
}
