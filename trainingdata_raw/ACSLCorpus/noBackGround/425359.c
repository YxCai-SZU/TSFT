#include <stdint.h>

/*@
    requires -100 <= x <= 100;
    ensures \result == 1 || \result == -1 || \result == 0;
    ensures (((\result) == 1) ==> ((x) > 0) &&
        ((\result) == -1) ==> ((x) < 0) &&
        ((\result) == 0) ==> ((x) == 0));
 */
int64_t func(int64_t x)
{
    int64_t ans;
    //@ assert -100 <= x <= 100;
    
    if (x > 0) {
        ans = 1;
        //@ assert ans == 1 && x > 0;
    } else if (x < 0) {
        ans = -1;
        //@ assert ans == -1 && x < 0;
    } else {
        ans = 0;
        //@ assert ans == 0 && x == 0;
    }
    
    //@ assert ans == 1 || ans == -1 || ans == 0;
    return ans;
}
