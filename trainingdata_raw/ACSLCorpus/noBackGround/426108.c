#include <stdint.h>

/*@
    requires (1 <= (x) <= 1000000000);
    ensures \result <= (2 * ((x) / 11) + 2);
    ensures \result >= (2 * ((x) / 11));
*/
uint64_t func(uint64_t x)
{
    uint64_t q;
    uint64_t r;
    uint64_t ans;
    uint64_t ceil_ans;

    q = x / 11;
    r = x % 11;
    ans = 2 * q;

    if (r == 6)
    {
        ans += 1;
    }
    else if (r >= 7)
    {
        ans += 2;
    }

    ceil_ans = 2 * q;
    //@ assert ceil_ans == 2 * (x / 11);
    
    if (r > 0)
    {
        ceil_ans += 1;
    }
    //@ assert ceil_ans <= 2 * (x / 11) + 1;
    
    if (r >= 7)
    {
        ceil_ans += 1;
    }
    //@ assert ceil_ans <= (2 * ((x) / 11) + 2);
    //@ assert ceil_ans >= (2 * ((x) / 11));

    return ans;
}
