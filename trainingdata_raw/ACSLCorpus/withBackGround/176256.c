#include <stdbool.h>

/*@ predicate valid_input(integer a, integer b) =
    a >= 1 && a <= 16 &&
    b >= 1 && b <= 16 &&
    a + b <= 16;
*/

/*@ predicate expected_result(integer a, integer b, bool result) =
    result == (a == 8 || b == 8 || a + b == 8);
*/

/*@
    requires \valid(v) && \valid(v+1);
    requires valid_input(v[0], v[1]);
    assigns \nothing;
    ensures expected_result(v[0], v[1], \result);
*/
bool func(int v[2])
{
    int a;
    int b;
    bool result;

    a = v[0];
    b = v[1];
    
    //@ assert a == v[0] && b == v[1];
    
    result = (a == 8) || (b == 8) || (a + b == 8);
    return result;
}
