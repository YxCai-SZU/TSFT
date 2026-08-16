#include <stdbool.h>

/*@
    predicate in_i32_range(integer x) = 
        x >= -2147483648 && x <= 2147483647;

    predicate func_spec(integer a, integer b, integer c) =
        a < b && b < c;
*/

/*@
    requires in_i32_range(a);
    requires in_i32_range(b);
    requires in_i32_range(c);
    ensures \result == true <==> func_spec(a, b, c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert in_i32_range(a);
    //@ assert in_i32_range(b);
    //@ assert in_i32_range(c);
    return a < b && b < c;
}
