#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (m) && (m) <= (n) &&
        (m) <= 5);
    ensures \result >= (100 * ((n) - (m)) + 1900 * (m));
    ensures \result == (100 * ((n) - (m)) + 1900 * (m)) || \result == (100 * ((n) - (m)) + 1900 * (m)) - 100;
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t result;
    int32_t ans;

    //@ assert (1 <= (n) && (n) <= 100 &&         1 <= (m) && (m) <= (n) &&         (m) <= 5);
    
    result = 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m;
    
    //@ assert result == (100 * ((n) - (m)) + 1900 * (m));
    
    if (result > 100 * (int32_t)n)
    {
        ans = result;
        //@ assert ans == (100 * ((n) - (m)) + 1900 * (m));
    }
    else
    {
        ans = 100 * (int32_t)n;
        //@ assert ans == 100 * n;
    }
    
    //@ assert ans >= (100 * ((n) - (m)) + 1900 * (m));
    //@ assert ans == (100 * ((n) - (m)) + 1900 * (m)) || ans == (100 * ((n) - (m)) + 1900 * (m)) - 100;
    
    return ans;
}
