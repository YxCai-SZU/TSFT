#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000);
    ensures \result == ((n) * ((n) - 1) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t ans;
    
    if (n < 2) {
        //@ assert n == 1;
        return 0;
    }
    
    //@ assert ((n) * ((n) - 1) / 2) <= 9223372036854775807 / 2;
    ans = n * (n - 1) / 2;
    
    //@ assert ans == ((n) * ((n) - 1) / 2);
    return ans;
}
