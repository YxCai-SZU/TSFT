#include <stddef.h>

/*@
    requires (1 <= (n) && 1 <= (k) && (n) <= 100000 && (k) <= (n));
    ensures \result == ((n) - (k) + 1);
*/
size_t func(size_t n, size_t k)
{
    //@ assert n - k + 1 == n - k + 1;
    return n - k + 1;
}
