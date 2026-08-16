#include <stdint.h>

/*@
    requires (2 <= (n) && (n) <= 100 &&
        2 <= (m) && (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    // Variable declarations at scope top
    int64_t result;

    //@ assert n > 1;
    //@ assert m > 1;
    //@ assert (n - 1) * (m - 1) >= 1;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;

    result = (n - 1) * (m - 1);
    return result;
}
