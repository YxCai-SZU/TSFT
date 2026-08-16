#include <stdbool.h>

/*@
    predicate in_i32_range(integer x) =
        -0x80000000 <= x <= 0x7FFFFFFF;

    predicate within_range(integer a, integer b, integer c) =
        a <= c && c <= b;
*/

/*@
    requires a <= b;
    requires in_i32_range(a);
    requires in_i32_range(b);
    requires in_i32_range(c);
    ensures \result == (a <= c && c <= b);
*/
bool func(int a, int b, int c)
{
    //@ assert a <= b;
    bool result;
    result = (a <= c && c <= b);
    
    //@ assert result == (a <= c && c <= b);
    return result;
}
