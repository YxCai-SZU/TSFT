#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == a - 2 * b || \result == 0;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t ans;
    // Variable declarations at top of scope
    ans = a - 2 * b;
    
    if (ans > 0)
    {
        //@ assert ans == a - 2 * b;
        return ans;
    }
    else
    {
        //@ assert ans == a - 2 * b;
        //@ assert ans <= 0;
        return 0;
    }
}
