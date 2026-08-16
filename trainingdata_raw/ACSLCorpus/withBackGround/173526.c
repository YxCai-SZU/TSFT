#include <stdbool.h>

/*@
    predicate in_range(integer v, integer low, integer high) =
        low <= v && v <= high;

    logic integer diff(integer x, integer a) = x - a;

    lemma diff_in_range:
        \forall integer a, b, x;
            in_range(a, 1, 100) && in_range(b, 1, 100) && in_range(x, 1, 200) ==>
            (diff(x, a) >= 0 && diff(x, a) <= b) == (x - a >= 0 && x - a <= b);
*/

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= x && x <= 200;
    ensures \result == (x - a >= 0 && x - a <= b);
*/
bool func(long a, long b, long x)
{
    long diff;
    bool result;

    diff = x - a;

    //@ assert in_range(a, 1, 100);
    //@ assert in_range(b, 1, 100);
    //@ assert in_range(x, 1, 200);

    if (diff < 0 || diff > b)
    {
        //@ assert diff < 0 || diff > b;
        //@ assert !(diff >= 0 && diff <= b);
        result = false;
    }
    else
    {
        //@ assert diff >= 0 && diff <= b;
        result = true;
    }

    //@ assert result == (diff >= 0 && diff <= b);
    return result;
}
