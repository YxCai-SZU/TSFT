#include <stdint.h>

/*@
    predicate is_small(integer x) = 1 <= x <= 9;
    predicate is_medium(integer x) = 1 <= x <= 20;
*/

/*@
    requires is_medium(a) && is_medium(b);
    ensures (a <= 9 && b <= 9 ==> \result == a * b) &&
            (a > 9 || b > 9 ==> \result == -1);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t max_val;
    int32_t result;

    //@ assert is_medium(a) && is_medium(b);
    
    if (a > b) {
        max_val = a;
    } else {
        max_val = b;
    }
    
    if (max_val <= 9) {
        //@ assert a <= 9 && b <= 9;
        //@ assert a * b <= 81;
        result = (int32_t)(a * b);
    } else {
        result = -1;
    }
    
    return result;
}
