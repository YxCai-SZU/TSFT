#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    ensures \result == (((a) == (b) && (b) == (c)) ? 1 :
        ((a) == (b) || (b) == (c) || (c) == (a)) ? 2 : 3);
    assigns \nothing;
*/
uint32_t func(int32_t a, int32_t b, int32_t c)
{
    uint32_t ans;
    //@ assert (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    
    if (a == b && b == c) {
        ans = 1;
        //@ assert ans == (((a) == (b) && (b) == (c)) ? 1 :         ((a) == (b) || (b) == (c) || (c) == (a)) ? 2 : 3);
    } else if (a == b || b == c || c == a) {
        ans = 2;
        //@ assert ans == (((a) == (b) && (b) == (c)) ? 1 :         ((a) == (b) || (b) == (c) || (c) == (a)) ? 2 : 3);
    } else {
        ans = 3;
        //@ assert ans == (((a) == (b) && (b) == (c)) ? 1 :         ((a) == (b) || (b) == (c) || (c) == (a)) ? 2 : 3);
    }
    
    //@ assert ans >= 1 && ans <= 3;
    return ans;
}
