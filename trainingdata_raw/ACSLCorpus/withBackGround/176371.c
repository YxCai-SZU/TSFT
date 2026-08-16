#include <limits.h>

/*@
    predicate in_range(integer v) = -100 <= v <= 100;

    logic integer sum(integer a, integer b) = a + b;
    logic integer diff(integer a, integer b) = a - b;
    logic integer prod(integer a, integer b) = a * b;

    lemma product_bounds: \forall integer a, b; in_range(a) && in_range(b) ==> -10000 <= prod(a,b) <= 10000;
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
    int res;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert -10000 <= a * b <= 10000;

    x = a + b;
    y = a - b;
    z = a * b;

    if (x > y && x > z)
    {
        res = x;
    }
    else if (y > z)
    {
        res = y;
    }
    else
    {
        res = z;
    }

    return res;
}
