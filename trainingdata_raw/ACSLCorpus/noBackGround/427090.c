#include <stdint.h>

/*@
    requires (1 <= (n) && 1 <= (m) && (n) <= 1000000000 && (m) <= 1000000000);
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    int64_t prev = -1;
    int64_t result = 0;
    int64_t i = 0;
    
    /*@
        loop invariant 0 <= i <= m;
        loop invariant result >= 0;
        loop invariant result <= i;
        loop invariant prev >= -1;
        loop invariant (1 <= (n) && 1 <= (m) && (n) <= 1000000000 && (m) <= 1000000000);
        loop assigns i, result, prev;
        loop variant m - i;
    */
    while (i < m)
    {
        int64_t x = (n < 2 * i) ? 0 : (n - 2 * i) - 1;
        int64_t y = (i > n) ? 0 : i;
        int64_t max_val = (x > y) ? x : y;
        
        //@ assert max_val >= 0;
        
        if (max_val != prev)
        {
            result += 1;
            prev = max_val;
        }
        
        i += 1;
    }
    
    return result;
}
