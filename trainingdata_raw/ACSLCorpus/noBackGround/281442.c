#include <stdint.h>

/*@
    requires (1 <= (a) <= 20 && 1 <= (b) <= 20);
    ensures (a < 10 && b < 10 ==> \result == (int)(a * b)) &&
            (a >= 10 || b >= 10 ==> \result == -1);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t ans;
    
    if (a < 10 && b < 10)
    {
        //@ assert 1 <= a && a <= 10;
        //@ assert 1 <= b && b <= 10;
        //@ assert a * b <= 100;
        ans = (int32_t)(a * b);
    }
    else
    {
        return -1;
    }
    
    //@ assert (a < 10 && b < 10 ==> ans == (int32_t)(a * b)) && (a >= 10 || b >= 10 ==> ans == -1);
    return ans;
}
