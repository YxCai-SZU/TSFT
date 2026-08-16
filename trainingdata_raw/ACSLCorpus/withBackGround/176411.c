#include <limits.h>

/*@
    predicate is_one_of(integer val, integer a, integer b, integer c, integer d) =
        val == a || val == b || val == c || val == d;

    predicate is_maximum(integer val, integer a, integer b, integer c, integer d) =
        val >= a && val >= b && val >= c && val >= d;
*/

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    requires -100 <= d <= 100;
    ensures is_one_of(\result, a, b, c, d);
    ensures is_maximum(\result, a, b, c, d);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_val;

    max_val = a;

    //@ assert is_one_of(max_val, a, b, c, d);
    //@ assert max_val >= a;

    if (b > max_val)
    {
        max_val = b;
        //@ assert is_one_of(max_val, a, b, c, d);
        //@ assert max_val >= a && max_val >= b;
    }

    //@ assert max_val >= a && max_val >= b;

    if (c > max_val)
    {
        max_val = c;
        //@ assert is_one_of(max_val, a, b, c, d);
        //@ assert max_val >= a && max_val >= b && max_val >= c;
    }

    //@ assert max_val >= a && max_val >= b && max_val >= c;

    if (d > max_val)
    {
        max_val = d;
        //@ assert is_one_of(max_val, a, b, c, d);
        //@ assert max_val >= a && max_val >= b && max_val >= c && max_val >= d;
    }

    //@ assert is_one_of(max_val, a, b, c, d);
    //@ assert is_maximum(max_val, a, b, c, d);
    return max_val;
}
