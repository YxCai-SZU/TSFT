#include <stdbool.h>

/*@
    predicate in_range(integer x) = 1 <= x && x <= 9;
    
    logic integer func_result(integer a, integer b, integer c) =
        (a == b && c != a) ? 1 : (a != b && a == c) ? 1 : (a != b && b == c) ? 1 : 0;
*/


bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    
    result = (a == b && c != a) || (a != b && a == c) || (a != b && b == c);
    
    return result;
}
