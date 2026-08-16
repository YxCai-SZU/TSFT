#include <stdint.h>

/*@
    requires (2 <= (a) <= 100) && (2 <= (b) <= 100);
    ensures \result == ((a) * (b) - ((a) + (b) - 1));
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t ans;
    int32_t ret_val;

    //@ assert (2 <= (a) <= 100);
    //@ assert (2 <= (b) <= 100);
    //@ assert a * b <= 10000;
    //@ assert a + b <= 200;
    //@ assert a * b >= a + b - 1;

    ans = a * b - (a + b - 1);
    ret_val = (int32_t)ans;
    //@ assert ret_val == ((a) * (b) - ((a) + (b) - 1));
    return ret_val;
}
