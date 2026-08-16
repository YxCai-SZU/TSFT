#include <stdint.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == (111 * ((a) + (b) + (c)));
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    // Variable declarations at top of scope
    int64_t sum;
    int64_t result;

    //@ assert 3 <= a + b + c <= 27;
    sum = a + b + c;

    //@ assert 333 <= 111 * sum <= 2997;
    result = 111 * sum;

    return result;
}
