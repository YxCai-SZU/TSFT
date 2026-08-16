#include <stdint.h>
#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_in_range:
        \forall integer x, y;
            in_range(x) && in_range(y) ==> -1000000000000000000 <= product(x, y) <= 1000000000000000000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    requires a <= b && c <= d;
    ensures \result == product(b, d) || \result == product(b, c) || \result == product(a, d) || \result == product(a, c);
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t xs[4];
    int64_t max_val;
    int64_t i;

    //@ assert -1000000000000000000 <= a * c <= 1000000000000000000;
    xs[0] = a * c;

    //@ assert -1000000000000000000 <= a * d <= 1000000000000000000;
    xs[1] = a * d;

    //@ assert -1000000000000000000 <= b * c <= 1000000000000000000;
    xs[2] = b * c;

    //@ assert -1000000000000000000 <= b * d <= 1000000000000000000;
    xs[3] = b * d;

    max_val = xs[0];
    i = 1;

    /*@
        loop invariant 1 <= i <= 4;
        loop invariant \exists integer j; 0 <= j < i && max_val == xs[j];
        loop invariant in_range(a) && in_range(b) && in_range(c) && in_range(d);
        loop invariant a <= b && c <= d;
        loop assigns i, max_val;
        loop variant 4 - i;
    */
    while (i < 4)
    {
        if (xs[i] > max_val)
        {
            max_val = xs[i];
        }
        i = i + 1;
    }

    return max_val;
}
