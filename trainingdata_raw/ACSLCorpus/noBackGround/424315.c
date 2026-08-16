#include <stdint.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == ((n) * 800 - ((n) / 15) * 200);
    assigns \nothing;
*/
int64_t func(uint64_t n)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert (1 <= (n) && (n) <= 100);
    
    //@ assert n * 800 <= 80000;
    //@ assert n / 15 <= 6;
    //@ assert (n / 15) * 200 <= 1200;
    //@ assert n / 15 >= 0;
    //@ assert (n / 15) * 200 >= 0;
    
    result = (int64_t)(n * 800 - (n / 15) * 200);
    
    //@ assert result == ((n) * 800 - ((n) / 15) * 200);
    
    return result;
}
