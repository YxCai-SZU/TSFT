#include <stddef.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result >= 0 && \result <= 100000;
    ensures \result >= (x / 11) * 2;
    assigns \nothing;
*/
size_t func(size_t x)
{
    size_t ans;
    size_t dd;
    
    ans = (x / 11) * 2;
    dd = x % 11;
    
    //@ assert ((ans) >= 0 && (ans) <= 100000 && (ans) >= ((x) / 11) * 2);
    
    if (dd >= 7)
    {
        ans += 2;
    }
    else
    {
        ans += 1;
    }
    
    //@ assert ((ans) >= 0 && (ans) <= 100000 && (ans) >= ((x) / 11) * 2);
    
    return ans;
}
