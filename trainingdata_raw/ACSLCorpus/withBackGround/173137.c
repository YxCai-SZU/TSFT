#include <stdbool.h>

/*@
    predicate strictly_increasing(integer a, integer b, integer c, integer d) =
        a < b && b < c && c < d;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> strictly_increasing(a, b, c, d);
    ensures \result == false <==> !strictly_increasing(a, b, c, d);
*/
bool func(int a, int b, int c, int d)
{
    bool result;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    //@ assert 1 <= d <= 100;

    if (a < b && b < c && c < d)
    {
        //@ assert strictly_increasing(a, b, c, d);
        result = true;
    }
    else
    {
        //@ assert !strictly_increasing(a, b, c, d);
        result = false;
    }

    return result;
}
