#include <stdbool.h>

/*@
    predicate can_distribute(integer a, integer b, integer c) =
        a + b == c || a + c == b || b + c == a;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true ==> can_distribute(a, b, c);
    ensures \result == false ==> !can_distribute(a, b, c);
*/
bool can_distribute_evenly(int a, int b, int c)
{
    bool result;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;

    if (a + b == c || b + c == a || c + a == b)
    {
        result = true;
        //@ assert can_distribute(a, b, c);
    }
    else
    {
        result = false;
        //@ assert !can_distribute(a, b, c);
    }

    return result;
}
