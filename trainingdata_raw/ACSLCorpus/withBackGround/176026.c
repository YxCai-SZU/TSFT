#include <stdint.h>

/*@
    predicate is_valid_params(integer x, integer y) =
        1 <= x && x <= 205 &&
        1 <= y && y <= 205;

    logic integer func_result(integer x, integer y) =
        (x == 1 && y == 1) ? 1000000000 :
        (x == 1 || y == 1) ? 600000000 : 400000000;

    lemma result_bound:
        \forall integer x, y;
        is_valid_params(x, y) ==> func_result(x, y) <= 1000000000;
*/

/*@
    requires is_valid_params(x, y);
    ensures \result == func_result(x, y);
    ensures \result <= 1000000000;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    uint32_t ans = 0;

    //@ assert is_valid_params(x, y);
    
    if (x == 1 && y == 1) {
        //@ assert func_result(x, y) == 1000000000;
        ans = 1000000000;
    } else if (x == 1 || y == 1) {
        //@ assert func_result(x, y) == 600000000;
        ans = 600000000;
    } else {
        //@ assert func_result(x, y) == 400000000;
        ans = 400000000;
    }

    //@ assert ans == func_result(x, y);
    //@ assert ans <= 1000000000;
    return ans;
}
