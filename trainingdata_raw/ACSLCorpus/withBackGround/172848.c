#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a && a <= 12 && 1 <= b && b <= 31;

    logic integer func_result(integer a, integer b) =
        a <= b ? 1 : 0;

    lemma result_bounds:
        \forall integer a, b;
        valid_range(a, b) ==> (func_result(a, b) == 0 || func_result(a, b) == 1);
*/

/*@
    requires valid_range(a, b);
    ensures \result == 0 || \result == 1;
    ensures \result == func_result(a, b);
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t ans;
    
    //@ assert valid_range(a, b);
    
    if (a <= b)
    {
        ans = 1;
        //@ assert ans == func_result(a, b);
    }
    else
    {
        ans = 0;
        //@ assert ans == func_result(a, b);
    }
    
    //@ assert ans == 0 || ans == 1;
    return ans;
}
