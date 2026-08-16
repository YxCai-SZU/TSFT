#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (6 * (r));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t pi;
    int64_t result;

    pi = 3;
    result = 2 * r * pi;

    //@ assert result == 2 * r * 3;
    //@ assert 2 * r * 3 == 6 * r;
    //@ assert result == 6 * r;

    return result;
}
