#include <stdbool.h>

/*@
    predicate is_ordered(integer a, integer b, integer c) =
        a <= b && b <= c;
*/

/*@
    requires -1000 <= a <= 1000;
    requires -1000 <= b <= 1000;
    requires -1000 <= c <= 1000;
    ensures \result == true <==> is_ordered(a, b, c);
*/
bool func(int a, int b, int c)
{
    bool result;
    
    //@ assert -1000 <= a <= 1000;
    //@ assert -1000 <= b <= 1000;
    //@ assert -1000 <= c <= 1000;
    
    if (a <= b && b <= c)
    {
        //@ assert is_ordered(a, b, c);
        result = true;
    }
    else
    {
        //@ assert !is_ordered(a, b, c);
        result = false;
    }
    
    //@ assert result == true <==> is_ordered(a, b, c);
    return result;
}
