#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= 100;
    //@ assert n == (int64_t)n && m == (int64_t)m;
    //@ assert n - 1 >= 0;
    //@ assert n - 1 <= 99;
    //@ assert m - 1 >= 0;
    //@ assert m - 1 <= 99;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;
    
    return (n - 1) * (m - 1);
}
