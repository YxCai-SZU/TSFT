#include <stddef.h>


size_t func(size_t n, size_t m)
{
    // Variable declarations at scope top
    size_t result;

    //@ assert n > 1 && m > 1;
    //@ assert (n - 1) <= 99;
    //@ assert (m - 1) <= 99;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;

    result = (n - 1) * (m - 1);
    return result;
}
