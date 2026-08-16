#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result >= 0;
    ensures \result <= 50;
    ensures \result * 2 <= n;
    ensures (\result - 1) * 2 < n;
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    uint32_t res;
    int32_t ret_val;

    res = n / 2;

    if (res >= 50)
    {
        ret_val = 50;
        //@ assert ret_val >= 0;
        //@ assert ret_val <= 50;
        //@ assert ret_val * 2 <= n;
        //@ assert (ret_val - 1) * 2 < n;
        return ret_val;
    }
    else
    {
        ret_val = (int32_t)res;
        //@ assert ret_val >= 0;
        //@ assert ret_val <= 50;
        //@ assert ret_val * 2 <= n;
        //@ assert (ret_val - 1) * 2 < n;
        return ret_val;
    }
}
