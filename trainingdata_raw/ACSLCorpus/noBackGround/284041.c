#include <stddef.h>

/*@
    requires (0 <= (n) <= 100 && 0 <= (m) <= 100);
    ensures \result == ((m) > (n) ? (n) + (m) - 1 : (n));
    ensures \result <= n + m;
    ensures \result >= n;
*/
size_t func(size_t n, size_t m)
{
    // Variable declarations at top of scope
    size_t result;

    if (m > n) {
        //@ assert n + m - 1 <= n + m;
        result = n + m - 1;
    } else {
        //@ assert n <= n + m;
        result = n;
    }

    return result;
}
