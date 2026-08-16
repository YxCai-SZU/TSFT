#include <stdint.h>

/*@
    predicate non_negative(integer x) = x >= 0;
    predicate bounded(integer x) = 0 <= x <= 1000000000;
    predicate result_condition(integer r, integer a, integer b) = 
        r >= 0 && (r == a - b * 2 || r == 0);
*/

/*@
    requires bounded(a) && bounded(b);
    ensures result_condition(\result, a, b);
*/
int32_t func(int32_t a, int32_t b) {
    int32_t result;
    //@ assert bounded(a) && bounded(b);
    result = a - b * 2;
    
    if (result > 0) {
        //@ assert result == a - b * 2;
        return result;
    } else {
        //@ assert result <= 0;
        return 0;
    }
}
