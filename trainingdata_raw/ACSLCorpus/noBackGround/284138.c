#include <stddef.h>

/*@
    requires (2 <= (n) && (n) <= 100 &&
        2 <= (m) && (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    // Variable declarations at scope top
    size_t result;

    //@ assert (2 <= (n) && (n) <= 100 &&         2 <= (m) && (m) <= 100);
    //@ assert n - 1 >= 1;
    //@ assert m - 1 >= 1;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;

    result = (n - 1) * (m - 1);
    //@ assert result == (((n) - 1) * ((m) - 1));
    return result;
}
