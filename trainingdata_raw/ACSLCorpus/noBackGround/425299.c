#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (800 * (n) - ((n) / 15) * 200);
    assigns \nothing;
*/
int64_t func(uint64_t n)
{
    uint64_t x;
    uint64_t r;
    int64_t a;
    int64_t b;
    int64_t result;

    x = n / 15;
    r = n % 15;
    a = 800 * (int64_t)n;
    b = 200 * (int64_t)x;

    //@ assert a == 800 * (int64_t)n;
    //@ assert b == 200 * (int64_t)x;
    //@ assert a - b == 800 * (int64_t)n - 200 * (int64_t)x;

    result = a - b;
    return result;
}
