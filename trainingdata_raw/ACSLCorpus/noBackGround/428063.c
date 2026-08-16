#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n) * (n));
    ensures \result >= 0;
    ensures \result <= n * n;
    ensures \result == ((m) >= (n) * (n) ? 0 : (n) * (n) - (m));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    // Variable declarations at top of scope
    int32_t result;
    uint32_t n_squared;

    //@ assert (1 <= (n) <= 100 && 0 <= (m) <= (n) * (n));
    
    n_squared = n * n;
    
    //@ assert n_squared <= 10000;
    //@ assert m <= n_squared;

    if (m >= n_squared)
    {
        //@ assert m >= n_squared;
        result = 0;
    }
    else
    {
        //@ assert m < n_squared;
        result = (int32_t)(n_squared - m);
    }

    //@ assert result >= 0;
    //@ assert result <= n_squared;
    //@ assert result == ((m) >= (n) * (n) ? 0 : (n) * (n) - (m));
    
    return result;
}
