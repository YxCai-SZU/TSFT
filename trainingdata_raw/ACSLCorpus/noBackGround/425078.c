#include <stdbool.h>
#include <stddef.h>

/*@
    requires (1 <= (h) && (h) <= 10000 &&
        1 <= (a) && (a) <= 10000);
    ensures ((\result) >= (h) / (a) &&
        ((h) % (a) == 0 ==> (\result) == (h) / (a)) &&
        ((h) % (a) != 0 ==> (\result) == (h) / (a) + 1));
*/
size_t func(size_t h, size_t a)
{
    size_t ans;
    //@ assert (1 <= (h) && (h) <= 10000 &&         1 <= (a) && (a) <= 10000);
    
    ans = h / a;
    
    if (h % a != 0)
    {
        ans += 1;
    }
    
    //@ assert ((ans) >= (h) / (a) &&         ((h) % (a) == 0 ==> (ans) == (h) / (a)) &&         ((h) % (a) != 0 ==> (ans) == (h) / (a) + 1));
    return ans;
}
