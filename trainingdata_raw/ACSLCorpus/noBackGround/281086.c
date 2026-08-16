#include <stdint.h>

/*@
    requires (1 <= (b) <= (a) <= 20 && 1 <= (c) <= 20);
    ensures \result >= 0 && \result <= c;
    ensures \result == c - (a - b) || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t diff;
    int64_t ans;
    int64_t res;
    
    diff = a - b;
    ans = c - diff;
    
    //@ assert ans == ((c) - (((a) - (b))));
    
    if (ans < 0)
    {
        res = 0;
    }
    else
    {
        res = ans;
    }
    
    //@ assert res == ((ans) < 0 ? 0 : (ans));
    //@ assert res >= 0 && res <= c;
    //@ assert res == c - (a - b) || res == 0;
    
    return res;
}
