#include <stdbool.h>

/*@
    predicate condition_holds(integer a, integer b, integer x) =
        x <= a + b && a <= x;
*/

/*@
    requires 0 <= a && a <= 100;
    requires 0 <= b && b <= 100;
    requires 0 <= x && x <= 100;
    ensures \result == (x <= a + b && a <= x);
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    bool result;
    
    //@ assert 0 <= a && a <= 100;
    //@ assert 0 <= b && b <= 100;
    //@ assert 0 <= x && x <= 100;
    
    if (x <= a + b && a <= x) {
        //@ assert condition_holds(a, b, x);
        result = true;
    } else {
        //@ assert !condition_holds(a, b, x);
        result = false;
    }
    
    //@ assert result == (x <= a + b && a <= x);
    return result;
}
