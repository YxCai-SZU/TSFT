#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;
    
    logic integer compute_res(integer a, integer b) =
        b - a * 2;
    
    predicate post_condition(integer res, integer a, integer b) =
        res >= 0 && res <= b && (res == compute_res(a, b) || res == 0);
*/

/*@
    requires valid_range(a, b);
    ensures post_condition(\result, a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    int res;
    
    //@ assert valid_range(a, b);
    
    res = b - a * 2;
    
    if (res > 0)
    {
        //@ assert res == compute_res(a, b);
        return res;
    }
    else
    {
        //@ assert res <= 0;
        return 0;
    }
}
