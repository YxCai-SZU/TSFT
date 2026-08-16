#include <stdint.h>

/*@
    requires (0 <= (a) && (a) < 24) && (0 <= (b) && (b) < 24) && (0 <= (c) && (c) < 24);
    ensures \result == ((a) + (b) + 1 <= 24 ? (a) + (b) + 1 : (a) + (b) + 1 - 24);
    ensures \result >= 1 && \result < 25;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    // Variable declarations at scope top
    uint32_t ans;

    //@ assert a + b + 1 >= 1;
    ans = a + b + 1;
    
    if (ans > 24) {
        //@ assert a + b + 1 - 24 >= 1;
        ans -= 24;
    }
    
    //@ assert ans == ((a) + (b) + 1 <= 24 ? (a) + (b) + 1 : (a) + (b) + 1 - 24);
    return ans;
}
