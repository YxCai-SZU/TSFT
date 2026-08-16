#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (p) <= 100);
    ensures \result >= 0 && \result <= n;
    ensures \result == n - p || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t p)
{
    // Variable declarations at scope top
    int64_t result;
    
    //@ assert 1 <= n <= 100;
    //@ assert 1 <= p <= 100;
    //@ assert n >= p || n < p;
    
    result = n - p;
    
    if (result > 0)
    {
        //@ assert result >= 0;
        //@ assert result <= n;
        return result;
    }
    else
    {
        return 0;
    }
}
