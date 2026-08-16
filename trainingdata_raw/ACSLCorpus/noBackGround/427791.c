#include <stdint.h>

/*@
    requires (-100 <= (x) <= 100);
    ensures \result == ((x) < 0 ? 0 : 10 * (x));
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t ans;
    
    //@ assert (-100 <= (x) <= 100);
    
    if (x < 0) {
        ans = 0;
    } else {
        //@ assert x >= 0;
        //@ assert 10 * x <= 1000;
        ans = 10 * x;
    }
    
    //@ assert ans == ((x) < 0 ? 0 : 10 * (x));
    return ans;
}
