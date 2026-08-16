#include <stdbool.h>

/*@
    predicate is_sum(integer a, integer b, integer c) =
        a + b == c || a + c == b || b + c == a;
*/

/*@
    requires 1 <= a <= 1000000000;
    requires 1 <= b <= 1000000000;
    requires 1 <= c <= 1000000000;
    ensures \result == true <==> is_sum(a, b, c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool a_bool;
    bool b_bool;
    bool c_bool;
    bool result;

    a_bool = false;
    b_bool = false;
    c_bool = false;

    //@ assert a + b >= 2;
    if (a + b == c) {
        a_bool = true;
    }
    //@ assert a + c >= 2;
    if (a + c == b) {
        b_bool = true;
    }
    //@ assert b + c >= 2;
    if (b + c == a) {
        c_bool = true;
    }

    //@ assert a_bool || b_bool || c_bool <==> is_sum(a, b, c);

    if (a_bool || b_bool || c_bool) {
        result = true;
    } else {
        result = false;
    }

    return result;
}
