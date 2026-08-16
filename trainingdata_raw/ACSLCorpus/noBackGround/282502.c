#include <stdint.h>

/*@
    requires 1 <= n <= 10000;
    ensures ((\result == 0 && n % 1000 == 0) || (\result == n % 1000));
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t res;
    
    //@ assert 1 <= n <= 10000;
    
    if (n % 1000 == 0)
    {
        res = 0;
        //@ assert res == 0 && n % 1000 == 0;
    }
    else
    {
        res = n % 1000;
        //@ assert res == n % 1000;
    }
    
    //@ assert (res == 0 && n % 1000 == 0) || (res == n % 1000);
    return res;
}
