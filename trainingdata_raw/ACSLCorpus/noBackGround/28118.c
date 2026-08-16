#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100);
    ensures \result >= 0 && (\result == a - 2 * b || \result == 0);
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t ans;
    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100);
    ans = a - 2 * b;
    
    if (ans > 0) {
        //@ assert ans == a - 2 * b;
        return ans;
    } else {
        //@ assert ans == a - 2 * b;
        return 0;
    }
}
