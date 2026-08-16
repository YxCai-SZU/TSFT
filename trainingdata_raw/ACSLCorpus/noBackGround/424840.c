#include <stdint.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == ((c) - ((a) - (b))) || \result == 0;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t ans;
    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    
    ans = c - (a - b);
    
    //@ assert ans == ((c) - ((a) - (b)));
    
    if (ans > 0)
    {
        //@ assert ans >= 0;
        return ans;
    }
    else
    {
        //@ assert 0 >= 0;
        return 0;
    }
}
