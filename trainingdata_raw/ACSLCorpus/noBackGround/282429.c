#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n) * (n));
    ensures \result == ((n) * (n)) - m;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    // Variable declarations at scope top
    int64_t n_squared;
    int64_t result;
    
    //@ assert n <= 100;
    //@ assert m >= 0;
    //@ assert ((n) * (n)) <= 10000;
    //@ assert ((n) * (n)) >= m;
    
    n_squared = n * n;
    result = n_squared - m;
    
    return result;
}
