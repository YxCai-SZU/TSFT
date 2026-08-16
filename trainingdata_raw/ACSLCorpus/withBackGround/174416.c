#include <stdbool.h>

/*@ predicate condition(integer a, integer b, integer c) =
      c >= b && c <= a + b;
*/

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    ensures \result == (c >= b && c <= a + b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool result;
    
    result = (c >= b && c <= a + b);
    //@ assert result == (c >= b && c <= a + b);
    return result;
}
