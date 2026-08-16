#include <limits.h>

/*@
    predicate in_range(integer v) = -100 <= v <= 100;

    logic integer sum(integer a, integer b) = a + b;
    logic integer diff(integer a, integer b) = a - b;
    logic integer prod(integer a, integer b) = a * b;

    lemma product_in_range:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> -10000 <= prod(a, b) <= 10000;
*/

/*@
    requires in_range(a) && in_range(b);
    ensures \result == sum(a, b) || \result == diff(a, b) || \result == prod(a, b);
    ensures \result >= sum(a, b);
    ensures \result >= diff(a, b);
    ensures \result >= prod(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    int x;
    int y;
    int z;
    int res;

    //@ assert in_range(a) && in_range(b);
    x = a + b;
    y = a - b;
    //@ assert -10000 <= a * b <= 10000;
    z = a * b;

    if (x > y)
    {
        if (x > z)
        {
            res = x;
        }
        else
        {
            res = z;
        }
    }
    else
    {
        if (y > z)
        {
            res = y;
        }
        else
        {
            res = z;
        }
    }

    //@ assert res == sum(a, b) || res == diff(a, b) || res == prod(a, b);
    //@ assert res >= sum(a, b);
    //@ assert res >= diff(a, b);
    //@ assert res >= prod(a, b);
    return res;
}
