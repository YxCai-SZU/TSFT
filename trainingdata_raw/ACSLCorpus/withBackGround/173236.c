#include <stdint.h>

/*@
    predicate max_val_is_valid(integer x, integer y, integer max_val) =
        (x > y ==> max_val == x) && (x <= y ==> max_val == y);
    
    logic integer compute_result(integer x, integer y, integer max_val) =
        (x == 1 && y == 1) ? 0 :
        (x == 1 || y == 1) ? max_val * 2 - 1 :
        (max_val - 1) * 2 + 1;
*/

/*@
    requires 1 <= x <= 205;
    requires 1 <= y <= 205;
    ensures \result <= 1000000;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    uint32_t max_val;
    uint32_t res;
    
    //@ assert 1 <= x <= 205;
    //@ assert 1 <= y <= 205;
    
    if (x > y) {
        max_val = x;
    } else {
        max_val = y;
    }
    
    //@ assert max_val_is_valid(x, y, max_val);
    //@ assert 1 <= max_val <= 205;
    
    if (x == 1 && y == 1) {
        res = 0;
    } else if (x == 1 || y == 1) {
        //@ assert max_val * 2 <= 410;
        res = max_val * 2 - 1;
    } else {
        //@ assert max_val > 0;
        //@ assert max_val * 2 <= 410;
        //@ assert (max_val - 1) * 2 <= 408;
        res = (max_val - 1) * 2 + 1;
    }
    
    //@ assert res == compute_result(x, y, max_val);
    //@ assert res <= 1000000;
    
    return res;
}
