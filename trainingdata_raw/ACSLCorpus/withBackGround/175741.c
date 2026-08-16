#include <stdint.h>

/*@
    predicate valid_x(integer x) = 1 <= x && x <= 179;

    logic integer formula1(integer x) = 180 - (x - 1);
    logic integer formula2(integer x) = 180 + (x - 1);

    lemma ans_range: \forall integer x; valid_x(x) ==> 
        (formula1(x) >= 1 && formula1(x) <= 360) && 
        (formula2(x) >= 1 && formula2(x) <= 360);
*/

/*@
    requires valid_x(x);
    ensures \result >= 1 && \result <= 360;
    ensures \result == formula1(x) || \result == formula2(x);
*/
int32_t func(uint32_t x) {
    int32_t ans;
    
    //@ assert valid_x(x);
    ans = 180 - ((int32_t)x - 1);
    
    if (x > 0 && x <= 90) {
        ans = 180 - ((int32_t)x - 1);
        //@ assert ans == formula1(x);
    } else if (x > 90 && x <= 179) {
        ans = 180 + ((int32_t)x - 1);
        //@ assert ans == formula2(x);
    }
    
    //@ assert ans >= 1 && ans <= 360;
    //@ assert ans == formula1(x) || ans == formula2(x);
    return ans;
}
