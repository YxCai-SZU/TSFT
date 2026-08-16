#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100 && 0 <= (r) && (r) <= 4111);
    ensures \result == ((n) >= 10 ? (r) : (r) + 100 * (10 - (n)));
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t r)
{
    int64_t ans;
    //@ assert (1 <= (n) && (n) <= 100 && 0 <= (r) && (r) <= 4111);
    
    if (n >= 10)
    {
        ans = r;
        //@ assert n >= 10 && ans == r;
    }
    else
    {
        ans = r + 100 * (10 - n);
        //@ assert n < 10 && ans == r + 100 * (10 - n);
    }
    
    //@ assert ans == ((n) >= 10 ? (r) : (r) + 100 * (10 - (n)));
    return ans;
}
