#include <stdint.h>

/*@
    requires (2 <= (k) && (k) <= (n) && (n) <= 100000);
    ensures \result <= n - 1;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t k)
{
    uint32_t ans;

    if (n == k)
    {
        ans = 0;
        //@ assert ans == 0;
    }
    else if (n % k == 0)
    {
        ans = 1;
        //@ assert ans == 1;
    }
    else
    {
        ans = 2;
        //@ assert ans == 2;
    }

    //@ assert ans == ((n) == (k) ? 0 : ((n) % (k) == 0 ? 1 : 2));
    //@ assert ans <= n - 1;
    return ans;
}
