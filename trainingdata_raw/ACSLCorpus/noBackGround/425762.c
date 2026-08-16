#include <stdint.h>

/*@
    requires (0 <= (a) <= 1000000000 &&
        0 <= (b) <= 1000000000 &&
        0 <= (c) <= 1000000000 &&
        1 <= (k) <= 100000000000000000);
    ensures ((\result) >= -(c) && (\result) <= (a));
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t ans;
    int64_t rst;
    
    ans = 0;
    rst = k;
    
    // Use all the A cards we have
    if (rst <= a)
    {
        ans = ans + rst;
        //@ assert ((ans) >= -(c) && (ans) <= (a));
        return ans;
    }
    
    rst = rst - a;
    ans = ans + a;
    
    // Use all the B cards we have
    if (rst <= b)
    {
        //@ assert ((ans) >= -(c) && (ans) <= (a));
        return ans;
    }
    
    rst = rst - b;
    ans = ans - rst;
    
    if (ans < -c)
    {
        ans = -c;
    }
    
    //@ assert ((ans) >= -(c) && (ans) <= (a));
    return ans;
}
