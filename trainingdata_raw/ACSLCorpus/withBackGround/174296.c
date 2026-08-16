#include <stdbool.h>

/*@
    predicate condition1(integer a, integer b, integer c, integer d) =
        a >= c && b >= c && a <= d && b <= d;
    predicate condition2(integer a, integer b, integer c, integer d) =
        a >= c && b <= d && b >= c && a <= d;
    lemma condition_equivalence:
        \forall integer a,b,c,d;
            (condition1(a,b,c,d) || condition2(a,b,c,d)) <==>
            ((a >= c && b >= c && a <= d && b <= d) || (a >= c && b <= d && b >= c && a <= d));
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> ((a >= c && b >= c && a <= d && b <= d) || (a >= c && b <= d && b >= c && a <= d));
*/
bool func(int a, int b, int c, int d)
{
    bool condition1;
    bool condition2;
    bool result;

    condition1 = (a >= c) && (b >= c) && (a <= d) && (b <= d);
    condition2 = (a >= c) && (b <= d) && (b >= c) && (a <= d);

    //@ assert condition1 || condition2 <==> ((a >= c && b >= c && a <= d && b <= d) || (a >= c && b <= d && b >= c && a <= d));

    if (condition1 || condition2)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
