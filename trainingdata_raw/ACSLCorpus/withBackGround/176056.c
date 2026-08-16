#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == a + b + c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at top of scope
    int result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    
    result = a + b + c;
    
    //@ assert result == a + b + c;
    return result;
}
