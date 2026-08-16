#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x && x <= 10;
    
    logic integer compute_result(integer x) = x + (x * x) + (x * x * x);
    
    lemma x_square_bounds:
        \forall integer x; valid_range(x) ==> 1 <= x * x && x * x <= 100;
    
    lemma x_cube_bounds:
        \forall integer x; valid_range(x) ==> 1 <= x * x * x && x * x * x <= 1000;
*/

/*@
    requires valid_range(x);
    ensures \result == compute_result(x);
    assigns \nothing;
*/
int32_t func(int32_t x)
{
    int32_t x2;
    int32_t x3;
    int32_t ans;
    
    //@ assert valid_range(x);
    
    //@ assert 1 <= x * x && x * x <= 100;
    x2 = x * x;
    
    //@ assert 1 <= x * x * x && x * x * x <= 1000;
    x3 = x * x * x;
    
    ans = x + x2 + x3;
    
    //@ assert ans == compute_result(x);
    return ans;
}
