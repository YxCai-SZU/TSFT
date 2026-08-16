#include <limits.h>

/*@
    predicate in_range(integer v) = -1000 <= v <= 1000;

    logic integer sum(integer a, integer b) = a + b;
    logic integer diff(integer a, integer b) = a - b;
    logic integer prod(integer a, integer b) = a * b;

    lemma product_in_range:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> -1000000 <= prod(a, b) <= 1000000;
*/

/*@
    requires in_range(a) && in_range(b);
    ensures \result == sum(a,b) || \result == diff(a,b) || \result == prod(a,b);
    ensures \result >= sum(a,b) && \result >= diff(a,b) && \result >= prod(a,b);
*/
int func(int a, int b)
{
    int x;
    int y;
    int z;
    int max_val;

    //@ assert in_range(a) && in_range(b);
    //@ assert -1000000 <= a * b <= 1000000;

    x = a + b;
    y = a - b;
    z = a * b;

    if (x > y)
    {
        if (x > z)
        {
            max_val = x;
        }
        else
        {
            max_val = z;
        }
    }
    else
    {
        if (y > z)
        {
            max_val = y;
        }
        else
        {
            max_val = z;
        }
    }

    //@ assert max_val == x || max_val == y || max_val == z;
    //@ assert max_val >= x && max_val >= y && max_val >= z;

    return max_val;
}
