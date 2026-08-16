#include <stdint.h>

/*@
    requires (0 <= (a) <= (b) <= 1000000000000000000ULL &&
        1 <= (x) <= 1000000000000000000ULL);
    ensures \result <= (b / x) - (a / x) + 1;
    ensures \result >= 0;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t x)
{
    //@ assert x > 0;
    //@ assert x <= 1000000000000000000ULL;
    //@ assert a <= b;
    //@ assert b <= 1000000000000000000ULL;
    //@ assert a / x <= b / x;
    //@ assert b / x <= b;
    //@ assert a / x <= a;
    //@ assert b / x >= a / x;
    //@ assert (b / x) - (a / x) <= 18446744073709551615ULL / x;
    //@ assert (b / x) - (a / x) <= 18446744073709551615ULL;

    uint64_t cnt;
    if (a % x == 0)
    {
        cnt = (b / x) - (a / x) + 1;
    }
    else
    {
        cnt = (b / x) - (a / x);
    }

    //@ assert cnt <= (b / x) - (a / x) + 1;
    //@ assert cnt >= 0;
    return cnt;
}
