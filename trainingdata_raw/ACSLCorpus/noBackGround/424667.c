#include <stddef.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    ensures \result == ((n) * (n) - (a));
    assigns \nothing;
*/
size_t func(size_t n, size_t a)
{
    // Variable declarations at scope top
    size_t ans;
    
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= a <= n * n;
    //@ assert n * n <= 10000;
    
    ans = n * n - a;
    
    //@ assert n * n >= a;
    //@ assert n * n <= 10000;
    //@ assert n * n - a <= 10000;
    
    return ans;
}
