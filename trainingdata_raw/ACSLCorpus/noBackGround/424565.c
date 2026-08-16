#include <stdint.h>

/*@
    requires (3 <= (n) && (n) <= 100);
    ensures \result == (((n) - 2) * 180);
    assigns \nothing;
*/
int64_t func(uint64_t n)
{
    int64_t result;
    //@ assert (3 <= (n) && (n) <= 100);
    result = ((int64_t)n - 2) * 180;
    //@ assert result == (((n) - 2) * 180);
    return result;
}
