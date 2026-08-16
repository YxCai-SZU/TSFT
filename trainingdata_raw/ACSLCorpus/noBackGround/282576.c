#include <stddef.h>

/*@
    requires 2 <= n <= 100000;
    ensures \result >= 0;
    ensures \result <= n - 1;
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t result;
    size_t n_minus_one;
    size_t half;
    size_t ans;
    
    if (n % 2 == 0)
    {
        result = n / 2 - 1;
        //@ assert result == (((n) % 2 == 0) ? (n) / 2 - 1 : ((n) - 1) / 2 + 1);
        return result;
    }
    else
    {
        n_minus_one = n - 1;
        half = n_minus_one / 2;
        ans = half + 1;
        //@ assert ans == (((n) % 2 == 0) ? (n) / 2 - 1 : ((n) - 1) / 2 + 1);
        return ans;
    }
}
