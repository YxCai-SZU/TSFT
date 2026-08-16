#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (w) && (w) <= 100);
    ensures \result == ((n) * (w));
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t w)
{
    // Variable declarations at top of scope
    int64_t result;

    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= w && w <= 100;
    //@ assert ((n) * (w)) <= 100 * 100;

    result = n * w;
    return result;
}
