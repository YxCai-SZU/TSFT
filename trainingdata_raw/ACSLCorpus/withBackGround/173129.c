#include <stdbool.h>

/*@
    predicate condition_holds(integer a, integer b, integer x) =
        b <= x && a + b >= x;
*/

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= x && x <= 100;
    requires x <= a + b;
    ensures \result == true <==> (b <= x && a + b >= x);
*/
bool func(long a, long b, long x)
{
    bool result;
    
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= x && x <= 100;
    //@ assert x <= a + b;
    
    if (b <= x && a + b >= x) {
        result = true;
        //@ assert condition_holds(a, b, x);
    } else {
        result = false;
        //@ assert !condition_holds(a, b, x);
    }
    
    //@ assert result == true <==> (b <= x && a + b >= x);
    return result;
}
