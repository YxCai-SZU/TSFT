#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= (n) &&
        (n) <= 1000000000000 &&
        (m) <= 1000000000000);
    ensures (1 <= (\result) <= (n));
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    int64_t result;
    //@ assert (1 <= (n) <= 100 &&         1 <= (m) <= (n) &&         (n) <= 1000000000000 &&         (m) <= 1000000000000);
    
    result = n - m + 1;
    
    if (result < 0)
    {
        result = 0;
    }
    
    //@ assert 0 <= result <= n;
    //@ assert result >= 1;
    
    return result;
}
