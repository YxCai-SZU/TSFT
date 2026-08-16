#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate valid_inputs(integer a, integer b) = 
        a_in_range(a) && b_in_range(b);
    
    logic integer compute_res(integer a, integer b) = a - b * 2;
    
    predicate valid_output(integer a, integer b, integer res) =
        res >= 0 && (res == compute_res(a, b) || res == 0);
*/

/*@
    requires valid_inputs(a, b);
    ensures valid_output(a, b, \result);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t res;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    
    res = a - b * 2;
    
    if (res > 0) {
        //@ assert res == compute_res(a, b);
        //@ assert res >= 0;
        return res;
    } else {
        //@ assert res <= 0;
        res = 0;
        //@ assert res >= 0;
        //@ assert res == 0;
        return res;
    }
}
