#include <limits.h>

/*@
    predicate valid_range(integer x) = 3 <= x <= 20;

    logic integer func_result(integer a, integer b) =
        a == b ? a + b :
        a < b ? 2 * a - 1 :
        2 * b - 1;

    lemma result_nonnegative:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> func_result(a, b) >= 0;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    
    if (a == b)
    {
        result = a + b;
    }
    else if (a < b)
    {
        result = 2 * a - 1;
    }
    else
    {
        result = 2 * b - 1;
    }
    
    //@ assert result == a + b || result == 2 * a - 1 || result == 2 * b - 1;
    //@ assert result >= 0;
    
    return result;
}
