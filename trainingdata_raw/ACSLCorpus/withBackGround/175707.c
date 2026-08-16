#include <stdbool.h>

/*@
    predicate is_consecutive(integer a, integer b, integer c) =
        (a == b + 1 && b == c + 1) || (a == b - 1 && b == c - 1);
*/

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> is_consecutive(a, b, c);
*/
bool func(int a, int b, int c)
{
    bool result;
    
    //@ assert 1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9;
    
    if ((a == b + 1 && b == c + 1) || (a == b - 1 && b == c - 1)) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
