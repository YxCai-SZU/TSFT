#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result <= c;
    ensures \result <= a + b + 1;
    ensures \result == c || \result == a + b + 1;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t ans;
    
    //@ assert 1 <= a + b + 1 <= 201;
    
    if (c < a + b + 1)
    {
        ans = c;
    }
    else
    {
        ans = a + b + 1;
    }
    
    //@ assert ans == ((c) < (a + b + 1) ? (c) : (a + b + 1));
    //@ assert ans <= c;
    //@ assert ans <= a + b + 1;
    //@ assert ans == c || ans == a + b + 1;
    
    return ans;
}
