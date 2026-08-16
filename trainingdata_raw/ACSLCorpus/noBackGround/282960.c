#include <stdint.h>

/*@
    requires (1 <= (n) <= 100000);
    ensures \result <= 1000;
    ensures \result == (((n) % 1000 != 0) ? (1000 - (n) % 1000) : 0);
*/
uint32_t func(uint32_t n)
{
    uint32_t ans;
    //@ assert (1 <= (n) <= 100000);
    
    if (n % 1000 != 0) {
        ans = 1000 - n % 1000;
        //@ assert ans == 1000 - n % 1000;
    } else {
        ans = 0;
        //@ assert ans == 0;
    }
    
    //@ assert ans == (((n) % 1000 != 0) ? (1000 - (n) % 1000) : 0);
    //@ assert ans <= 1000;
    
    return ans;
}
