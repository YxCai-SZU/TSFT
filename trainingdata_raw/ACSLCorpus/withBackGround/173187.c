#include <stdbool.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 100;

    predicate condition_holds(integer a, integer b, integer c, integer d, integer e) =
        a <= c && c <= b && c <= d && d <= e;

    lemma condition_implies_true:
        \forall integer a, b, c, d, e;
            in_range(a) && in_range(b) && in_range(c) && in_range(d) && in_range(e) &&
            condition_holds(a, b, c, d, e) ==>
            condition_holds(a, b, c, d, e);
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d) && in_range(e);
    ensures \result == true <==> condition_holds(a, b, c, d, e);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d, int e)
{
    bool result;

    //@ assert in_range(a) && in_range(b) && in_range(c) && in_range(d) && in_range(e);

    if (a <= c && c <= b && c <= d && d <= e)
    {
        result = true;
        //@ assert condition_holds(a, b, c, d, e);
    }
    else
    {
        result = false;
        //@ assert !condition_holds(a, b, c, d, e);
    }

    return result;
}
