#include <stddef.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures \result == ((n) * (m));
*/
size_t func(size_t n, size_t m)
{
    //@ assert n <= 100 && m <= 100;
    //@ assert n * m <= 10000;
    return n * m;
}
