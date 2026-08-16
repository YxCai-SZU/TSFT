#include <stdint.h>

/*@
    predicate in_range(integer x, integer low, integer high) =
        low <= x && x <= high;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bounds:
        \forall integer a, b;
        in_range(a, -1000000000, 1000000000) && in_range(b, -1000000000, 1000000000) ==>
        in_range(product(a, b), -1000000000000000000, 1000000000000000000);
*/

/*@
    requires in_range(a, -1000000000, 1000000000) && in_range(b, -1000000000, 1000000000) && a <= b;
    requires in_range(c, -1000000000, 1000000000) && in_range(d, -1000000000, 1000000000) && c <= d;
    ensures \result == a*d || \result == a*c || \result == b*d || \result == b*c;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t v[4];
    int64_t max_value;
    int64_t i;

    //@ assert in_range(a*c, -1000000000000000000, 1000000000000000000);
    v[0] = a * c;

    //@ assert in_range(a*d, -1000000000000000000, 1000000000000000000);
    v[1] = a * d;

    //@ assert in_range(b*c, -1000000000000000000, 1000000000000000000);
    v[2] = b * c;

    //@ assert in_range(b*d, -1000000000000000000, 1000000000000000000);
    v[3] = b * d;

    max_value = v[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_value == v[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_value >= v[j];
        loop invariant in_range(v[0], -1000000000000000000, 1000000000000000000);
        loop invariant in_range(v[1], -1000000000000000000, 1000000000000000000);
        loop invariant in_range(v[2], -1000000000000000000, 1000000000000000000);
        loop invariant in_range(v[3], -1000000000000000000, 1000000000000000000);
        loop invariant in_range(max_value, -1000000000000000000, 1000000000000000000);
        loop invariant in_range(a, -1000000000, 1000000000) && in_range(b, -1000000000, 1000000000) && a <= b;
        loop invariant in_range(c, -1000000000, 1000000000) && in_range(d, -1000000000, 1000000000000) && c <= d;
        loop assigns i, max_value;
        loop variant 4 - i;
    */
    while (i < 4)
    {
        if (v[i] > max_value)
        {
            max_value = v[i];
        }
        i = i + 1;
    }

    //@ assert max_value == v[0] || max_value == v[1] || max_value == v[2] || max_value == v[3];
    return max_value;
}
