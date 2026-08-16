#include <stdbool.h>

/*@
    predicate all_equal(integer a, integer b, integer c) =
        a == b && b == c;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> a == b && b == c;
    ensures \result == false <==> a != b || b != c;
*/
bool func(int a, int b, int c)
{
    bool result;
    
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    
    if (a == b && b == c) {
        //@ assert a == b && b == c;
        result = true;
    } else {
        //@ assert a != b || b != c;
        result = false;
    }
    
    //@ assert result == true <==> a == b && b == c;
    return result;
}
