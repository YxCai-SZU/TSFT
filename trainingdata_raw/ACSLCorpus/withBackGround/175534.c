#include <stdbool.h>

/*@
    predicate condition(integer a, integer b, integer x) =
        x <= a + b && a <= x;
*/

/*@
    requires 0 <= a && a <= 100;
    requires 0 <= b && b <= 100;
    requires 0 <= x && x <= 100;
    ensures \result == (x <= a + b && a <= x);
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long x)
{
    bool result;
    
    //@ assert condition(a, b, x) <==> (x <= a + b && a <= x);
    
    if (x <= a + b && a <= x)
    {
        //@ assert condition(a, b, x);
        result = true;
    }
    else
    {
        //@ assert !condition(a, b, x);
        result = false;
    }
    
    return result;
}
