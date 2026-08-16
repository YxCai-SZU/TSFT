#include <stddef.h>

/*@
    requires 1 <= n <= 1000000000;
    requires 1 <= m <= 1000000000;
    ensures n < m ==> \result == 0;
    ensures n >= m ==> \result == n - m + 1;
    assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    size_t res;
    
    if (n < m)
    {
        //@ assert n < m;
        res = 0;
    }
    else
    {
        //@ assert n >= m;
        res = n - m + 1;
    }
    
    return res;
}
