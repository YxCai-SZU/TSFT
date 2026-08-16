#include <stdbool.h>

/*@
    predicate is_sum_eq(integer a, integer b, integer c) =
        a == b + c || b == a + c || c == a + b;
 */

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    requires a + b + c == 100;
    ensures \result == true <==> is_sum_eq(a, b, c);
 */
bool func(int a, int b, int c)
{
    bool result;
    //@ assert a + b + c == 100;
    
    if (a == b + c || b == a + c || c == a + b)
    {
        result = true;
        //@ assert is_sum_eq(a, b, c);
    }
    else
    {
        //@ assert !is_sum_eq(a, b, c);
        result = false;
    }
    
    return result;
}
