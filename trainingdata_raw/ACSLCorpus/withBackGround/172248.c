#include <limits.h>

/*@
    predicate is_one_of(integer val, integer a, integer b, integer c, integer d) =
        val == a || val == b || val == c || val == d;

    predicate in_range(integer x) = -100 <= x <= 100;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures is_one_of(\result, a, b, c, d);
    ensures \result >= -100;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int min;

    min = a;

    //@ assert is_one_of(min, a, b, c, d);
    //@ assert min >= -100;

    if (b < min)
    {
        min = b;
        //@ assert is_one_of(min, a, b, c, d);
        //@ assert min >= -100;
    }

    if (c < min)
    {
        min = c;
        //@ assert is_one_of(min, a, b, c, d);
        //@ assert min >= -100;
    }

    if (d < min)
    {
        min = d;
        //@ assert is_one_of(min, a, b, c, d);
        //@ assert min >= -100;
    }

    //@ assert is_one_of(min, a, b, c, d);
    //@ assert min >= -100;

    return min;
}
