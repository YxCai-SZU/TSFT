#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 0;
    ensures \result <= ((a) + (b) + (c));
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t ans = 0;
    int64_t c_temp;
    int64_t a_temp;

    if (c > 0)
    {
        if (b < c)
        {
            ans += b * 2 + 1;
            c_temp = c - (b + 1);
            a_temp = (a > 1) ? (a - 1) : 0;
            //@ assert ans >= 0;
            ans += (a_temp + 1 < c_temp) ? (a_temp + 1) : c_temp;
        }
        else
        {
            ans += c * 2;
        }
    }

    //@ assert ans >= 0;
    //@ assert ans <= ((a) + (b) + (c));
    return ans;
}
