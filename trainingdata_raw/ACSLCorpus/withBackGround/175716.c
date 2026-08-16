#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 3 <= a && a <= 20;
    predicate b_in_range(integer b) = 3 <= b && b <= 20;
    predicate valid_result(integer a, integer b, integer result) =
        result == a + b || result == b * 2 - 1 || result == a * 2 - 1;
    predicate result_non_negative(integer result) = result >= 0;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures valid_result(a, b, \result) && result_non_negative(\result);
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    
    //@ assert a_in_range(a) && b_in_range(b);
    
    if (a >= b + 1)
    {
        //@ assert a >= b + 1;
        result = a + b;
    }
    else if (b >= a + 1)
    {
        //@ assert b >= a + 1;
        result = b * 2 - 1;
    }
    else
    {
        //@ assert a < b + 1 && b < a + 1;
        result = a * 2 - 1;
    }
    
    //@ assert valid_result(a, b, result);
    //@ assert result_non_negative(result);
    
    return result;
}
