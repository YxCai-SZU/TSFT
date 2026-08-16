#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (800 * (n) - ((n) / 15) * 200);
    assigns \nothing;
*/
int64_t func(uint64_t n)
{
    // Variable declarations at top of scope
    int64_t result;

    //@ assert (1 <= (n) && (n) <= 100);

    //@ assert 800 * n <= 800 * 100;
    //@ assert n / 15 <= n;
    //@ assert 200 * (n / 15) <= 200 * n;

    result = 800 * (int64_t)n - (int64_t)(n / 15) * 200;
    
    //@ assert result == (800 * (n) - ((n) / 15) * 200);
    
    return result;
}
