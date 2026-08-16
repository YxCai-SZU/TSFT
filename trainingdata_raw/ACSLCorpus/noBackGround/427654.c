#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
    ensures \result <= c;
    ensures \result <= b / a;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c)
{
    uint64_t ans;
    uint64_t tmp;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         1 <= (c) && (c) <= 100);
    
    tmp = b / a;
    if (tmp < c) {
        ans = tmp;
    } else {
        ans = c;
    }
    
    //@ assert ans <= c;
    //@ assert ans <= b / a;
    
    return ans;
}
