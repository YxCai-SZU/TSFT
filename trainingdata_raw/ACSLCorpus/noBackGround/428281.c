#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    ensures \result == n * n - a;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t a)
{
    // Variable declarations at scope top
    int64_t nn;
    int64_t result;

    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= a <= n * n;
    
    //@ assert n * n <= 100 * 100;
    nn = n * n;
    
    //@ assert nn >= a;
    result = nn - a;
    
    //@ assert result == n * n - a;
    return result;
}
