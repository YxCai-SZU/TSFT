#include <limits.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;

    logic integer sum_two(integer a, integer b) = a + b;

    lemma min_is_one_of:
        \forall integer p, q, r, x, y, z, min;
        valid_range(p) && valid_range(q) && valid_range(r) &&
        x == sum_two(p, q) && y == sum_two(q, r) && z == sum_two(p, r) &&
        (min == x || min == y || min == z) ==>
        (min == sum_two(p, q) || min == sum_two(q, r) || min == sum_two(p, r));

    lemma min_le_total:
        \forall integer p, q, r, x, y, z, min;
        valid_range(p) && valid_range(q) && valid_range(r) &&
        x == sum_two(p, q) && y == sum_two(q, r) && z == sum_two(p, r) &&
        (min == x || min == y || min == z) ==>
        min <= p + q + r;
*/

/*@
    requires valid_range(p);
    requires valid_range(q);
    requires valid_range(r);
    ensures \result == p + q || \result == q + r || \result == p + r;
    ensures \result <= p + q + r;
*/
int func(int p, int q, int r)
{
    int x;
    int y;
    int z;
    int min_value;

    x = p + q;
    y = q + r;
    z = p + r;

    min_value = x;

    //@ assert min_value == x || min_value == y || min_value == z;
    if (y < min_value)
    {
        min_value = y;
        //@ assert min_value == x || min_value == y || min_value == z;
    }

    //@ assert min_value == x || min_value == y || min_value == z;
    if (z < min_value)
    {
        min_value = z;
        //@ assert min_value == x || min_value == y || min_value == z;
    }

    //@ assert min_value == x || min_value == y || min_value == z;
    //@ assert min_value <= p + q + r;

    return min_value;
}
