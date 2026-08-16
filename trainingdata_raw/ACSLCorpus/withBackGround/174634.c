#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    predicate is_sum_relation(integer a, integer b, integer c) =
        a == b + c || b == a + c || c == a + b;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    ensures \result == true <==> is_sum_relation(a, b, c);
*/
bool func(int a, int b, int c)
{
    bool result;
    
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    
    result = (a == b + c) || (b == a + c) || (c == a + b);
    
    //@ assert result == true <==> is_sum_relation(a, b, c);
    return result;
}
