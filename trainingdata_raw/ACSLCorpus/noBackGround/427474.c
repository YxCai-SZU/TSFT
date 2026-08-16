#include <stddef.h>

/*@
    requires (1 <= (n) <= 100 &&
        0 <= (a) <= (n) * (n));
    ensures \result == n * n - a;
    assigns \nothing;
*/
size_t func(size_t n, size_t a)
{
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= a <= n * n;
    //@ assert n * n <= 100 * 100;
    //@ assert n * n >= a;
    
    size_t ans = n * n - a;
    return ans;
}
