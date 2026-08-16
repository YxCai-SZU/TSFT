#include <stdbool.h>

/*@
    predicate in_range(integer a, integer b, integer c) =
        c >= a && c <= b;
*/

/*@
    requires a < 0x80000000;
    requires b < 0x80000000;
    requires c < 0x80000000;
    ensures \result == (c >= a && c <= b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert a < 0x80000000;
    //@ assert b < 0x80000000;
    //@ assert c < 0x80000000;
    
    bool result;
    result = (c >= a && c <= b);
    
    //@ assert result == (c >= a && c <= b);
    return result;
}
