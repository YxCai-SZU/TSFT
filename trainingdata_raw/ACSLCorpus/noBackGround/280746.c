#include <stdint.h>

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures \result >= 0;
    ensures \result == n - 2 * m || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    int64_t result;
    result = n - 2 * m;
    
    if (result < 0)
    {
        result = 0;
    }
    
    //@ assert ((result) >= 0);
    return result;
}
