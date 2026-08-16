#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 1000000000 &&
        0 <= (b) && (b) <= 1000000000 &&
        0 <= (c) && (c) <= 1000000000);
    ensures \result == ((c) <= (a) + (b) + 1 ?
            ((b) <= (c) ? (c) - (b) : 0) :
            (b) + 1 + (b));
    ensures \result <= a + b + 1 + b;
    ensures \result >= 0;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c)
{
    uint64_t ans;

    //@ assert (0 <= (a) && (a) <= 1000000000 &&         0 <= (b) && (b) <= 1000000000 &&         0 <= (c) && (c) <= 1000000000);
    
    if (c <= a + b + 1)
    {
        if (b <= c)
        {
            ans = c - b;
            //@ assert ans == c - b;
        }
        else
        {
            ans = 0;
            //@ assert ans == 0;
        }
        //@ assert ans == ((c) <= (a) + (b) + 1 ?             ((b) <= (c) ? (c) - (b) : 0) :             (b) + 1 + (b));
    }
    else
    {
        ans = b + 1 + b;
        //@ assert ans == b + 1 + b;
    }

    //@ assert ans == ((c) <= (a) + (b) + 1 ?             ((b) <= (c) ? (c) - (b) : 0) :             (b) + 1 + (b));
    //@ assert ans <= a + b + 1 + b;
    //@ assert ans >= 0;
    
    return ans;
}
