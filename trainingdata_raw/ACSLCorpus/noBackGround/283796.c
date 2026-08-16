#include <stdint.h>

/*@
    requires ((a) >= 1 && (a) <= 100 &&
        (b) >= 1 && (b) <= 100);
    ensures \result >= 0;
    ensures \result == (((a) - (b) * 2) > 0 ? ((a) - (b) * 2) : 0);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    // Variable declarations at top of scope
    int64_t ans;
    
    //@ assert b * 2 <= 200;
    //@ assert a >= 1;
    //@ assert a - b * 2 <= 99;
    
    ans = a - b * 2;
    
    if (ans > 0) {
        return ans;
    } else {
        return 0;
    }
}
