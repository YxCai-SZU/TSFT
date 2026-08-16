#include <stdbool.h>

/*@
    predicate condition_holds(integer a, integer b, integer c, integer d) =
        a >= b && c >= d;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> a >= b && c >= d;
*/
bool func(int a, int b, int c, int d)
{
    bool result;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    //@ assert 1 <= d <= 100;

    if (a >= b && c >= d) {
        //@ assert condition_holds(a, b, c, d);
        result = true;
    } else {
        //@ assert !condition_holds(a, b, c, d);
        result = false;
    }

    //@ assert result == true <==> condition_holds(a, b, c, d);
    return result;
}
