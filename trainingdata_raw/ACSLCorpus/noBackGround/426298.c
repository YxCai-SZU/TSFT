#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= (n));
    ensures \result >= 0;
    ensures \result <= n;
    ensures \result == ((m) == 1 ?
            ((n) == 1 ? 0 : (n) - 1)
        :
            ((n) == (m) ? 0 : (n) - (m)));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t ans;
    //@ assert (1 <= (n) <= 100 && 1 <= (m) <= (n));
    
    if (m == 1)
    {
        if (n == 1)
        {
            ans = 0;
            //@ assert ans == 0;
        }
        else
        {
            ans = (int32_t)(n - 1);
            //@ assert ans == n - 1;
        }
    }
    else
    {
        if (n == m)
        {
            ans = 0;
            //@ assert ans == 0;
        }
        else
        {
            ans = (int32_t)(n - m);
            //@ assert ans == n - m;
        }
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= n;
    //@ assert ans == ((m) == 1 ?             ((n) == 1 ? 0 : (n) - 1)         :             ((n) == (m) ? 0 : (n) - (m)));
    return ans;
}
