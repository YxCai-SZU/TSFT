#include <stdint.h>

/*@ predicate non_negative(integer x) = x >= 0; */

/*@
    requires 1 <= n <= 1000000000;
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    uint64_t n_unsigned;
    uint64_t ans;
    
    //@ assert 1 <= n <= 1000000000;
    
    if (n < 0)
    {
        n_unsigned = 0;
    }
    else
    {
        n_unsigned = (uint64_t)n;
    }
    
    ans = ((n_unsigned + 1) / 2) / 2;
    
    //@ assert ans <= n_unsigned;
    
    return (int64_t)ans;
}
