#include <stdbool.h>

/*@
    predicate valid_params(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_result(integer a, integer b, integer c) =
        c - (a - b);

    predicate result_property(integer ret, integer a, integer b, integer c) =
        ret >= 0 &&
        ret <= c &&
        (ret == compute_result(a, b, c) || ret == 0);
*/

/*@
    requires valid_params(a, b, c);
    ensures result_property(\result, a, b, c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int ret;

    //@ assert valid_params(a, b, c);
    
    result = c - (a - b);
    
    if (result < 0)
    {
        ret = 0;
    }
    else
    {
        ret = result;
    }
    
    //@ assert ret >= 0;
    //@ assert ret <= c;
    //@ assert ret == compute_result(a, b, c) || ret == 0;
    
    return ret;
}
