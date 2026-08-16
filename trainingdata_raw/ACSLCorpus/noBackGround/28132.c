#include <stdint.h>

/*@
    requires ((1 <= ((a)) <= 100) && (1 <= ((b)) <= 100) && (1 <= ((c)) <= 100) && (1 <= ((d)) <= 100));
    ensures \result >= 0;
    ensures \result <= b;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t ans = 0;
    int64_t b_local = b;
    int64_t c_temp;
    int64_t d_temp;
    int64_t min_val;

    if (c > b_local)
    {
        ans = ans + b_local;
        c_temp = c - b_local;
        d_temp = d;
        //@ assert c_temp >= 0;
        if (c_temp < d_temp)
        {
            min_val = c_temp;
        }
        else
        {
            min_val = d_temp;
        }
        //@ assert min_val >= 0;
        ans = ans + min_val;
    }
    else
    {
        ans = ans + c;
    }

    //@ assert ans >= 0;
    if (ans > b_local)
    {
        ans = b_local;
    }

    //@ assert ans <= b_local;
    return ans;
}
