#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer sum(integer a, integer b) = a + b;

    logic integer min_of_three(integer a, integer b, integer c) =
        (a <= b && a <= c) ? a : ((b <= c) ? b : c);

    lemma min_bound:
        \forall integer p, q, r;
            valid_range(p) && valid_range(q) && valid_range(r) ==>
            min_of_three(p+q, q+r, r+p) <= p + q + q + r;
*/

/*@
    requires valid_range(p);
    requires valid_range(q);
    requires valid_range(r);
    ensures \result == p+q || \result == q+r || \result == r+p;
    ensures \result <= p + q + q + r;
*/
int func(int p, int q, int r)
{
    int min1;
    int min2;

    //@ assert 1 <= p <= 100;
    //@ assert 1 <= q <= 100;
    //@ assert 1 <= r <= 100;

    if (p + q < q + r) {
        min1 = p + q;
    } else {
        min1 = q + r;
    }

    //@ assert min1 == p+q || min1 == q+r;

    if (min1 < r + p) {
        min2 = min1;
    } else {
        min2 = r + p;
    }

    //@ assert min2 == min_of_three(p+q, q+r, r+p);
    //@ assert min2 <= p + q + q + r;

    return min2;
}
