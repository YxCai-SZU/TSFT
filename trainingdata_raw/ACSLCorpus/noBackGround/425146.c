#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n) * (n));
    ensures \result == ((n) * (n) - (m));
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t m)
{
    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= m && m <= n * n;
    //@ assert n * n <= 10000;
    //@ assert n * n - m >= 0;
    
    return n * n - m;
}
