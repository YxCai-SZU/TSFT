#include <stdbool.h>

/*@
    predicate valid_params(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_x(integer a, integer b, integer c) =
        a - b + c;

    lemma x_bounds:
        \forall integer a, b, c;
        valid_params(a, b, c) ==>
        compute_x(a, b, c) >= 0 &&
        compute_x(a, b, c) <= a - b + c;
*/

/*@
    requires valid_params(a, b, c);
    ensures \result >= 0;
    ensures \result <= a - b + c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int x;
    int result;

    //@ assert valid_params(a, b, c);
    x = a - b + c;

    if (x < 0)
    {
        result = 0;
        //@ assert result >= 0;
        return result;
    }
    else
    {
        //@ assert x >= 0;
        
        if (x < a - b + c)
        {
            result = x;
        }
        else
        {
            result = a - b + c;
        }
        //@ assert result <= a - b + c;
        return result;
    }
}
