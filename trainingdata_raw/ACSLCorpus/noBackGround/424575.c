#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result <= c;
    ensures \result <= a + (b / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t ans;
    
    //@ assert a + (b / 2) <= 200;
    //@ assert b / 2 <= 50;
    
    if (c < a + (b / 2)) {
        ans = c;
    } else {
        ans = a + (b / 2);
    }
    
    //@ assert ans <= c;
    //@ assert ans <= a + (b / 2);
    
    return ans;
}
