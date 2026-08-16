#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= -1 && \result <= 200;
    ensures \result == -1 || \result == a + b;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t sum;
    int32_t ret_val;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    sum = a + b;
    
    //@ assert 2 <= sum <= 200;
    
    if (sum >= 10)
    {
        ret_val = -1;
    }
    else
    {
        ret_val = (int32_t)sum;
    }
    
    //@ assert ret_val >= -1 && ret_val <= 200;
    return ret_val;
}
