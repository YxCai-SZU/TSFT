#include <stdint.h>

/*@
    requires (1 <= (n) && 1 <= (m) && (n) <= 1000000000000 && (m) <= 1000000000000);
    ensures \result <= n + m;
    ensures \result >= 0;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t ans = 0;

    //@ assert (1 <= (n) && 1 <= (m) && (n) <= 1000000000000 && (m) <= 1000000000000);
    
    if (n > m * 2)
    {
        ans = m * 2 + (n - m * 2) / 4;
    }
    else
    {
        ans = n / 2 + (m - n / 2);
    }

    //@ assert ans == ((n) > (m) * 2 ? (m) * 2 + ((n) - (m) * 2) / 4 : (n) / 2 + ((m) - (n) / 2));
    //@ assert ans <= n + m;
    //@ assert ans >= 0;

    return ans;
}
