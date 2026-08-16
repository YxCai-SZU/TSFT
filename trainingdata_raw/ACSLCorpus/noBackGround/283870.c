#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n) * (n));
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> ((m) >= (n) || (m) <= 0);
    ensures \result == 0 ==> ((m) < (n) && (m) > 0);
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t res;
    
    //@ assert (1 <= (n) <= 100 && 0 <= (m) <= (n) * (n));
    
    if (m >= n || m <= 0)
    {
        res = 1;
    }
    else
    {
        res = 0;
    }
    
    //@ assert res == 1 || res == 0;
    //@ assert res == 1 ==> ((m) >= (n) || (m) <= 0);
    //@ assert res == 0 ==> ((m) < (n) && (m) > 0);
    
    return res;
}
