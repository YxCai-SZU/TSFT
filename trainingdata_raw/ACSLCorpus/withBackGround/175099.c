#include <stdint.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate product_in_range(integer v) = -1000000000000000000 <= v <= 1000000000000000000;
    logic integer max_of_four(integer x0, integer x1, integer x2, integer x3) =
        (x0 >= x1 && x0 >= x2 && x0 >= x3) ? x0 :
        (x1 >= x2 && x1 >= x3) ? x1 :
        (x2 >= x3) ? x2 : x3;
    lemma max_is_one_of:
        \forall integer a,b,c,d;
        in_range(a) && in_range(b) && in_range(c) && in_range(d) && a <= b && c <= d ==>
        max_of_four(a*c, a*d, b*c, b*d) == b*d ||
        max_of_four(a*c, a*d, b*c, b*d) == a*d ||
        max_of_four(a*c, a*d, b*c, b*d) == b*c ||
        max_of_four(a*c, a*d, b*c, b*d) == a*c;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    requires a <= b && c <= d;
    ensures \result == b*d || \result == a*d || \result == b*c || \result == a*c;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t xs[4];
    int64_t max_val;
    int64_t i;

    //@ assert product_in_range(a*c);
    xs[0] = a * c;
    //@ assert product_in_range(a*d);
    xs[1] = a * d;
    //@ assert product_in_range(b*c);
    xs[2] = b * c;
    //@ assert product_in_range(b*d);
    xs[3] = b * d;

    max_val = xs[0];
    i = 1;
    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_val == xs[k];
        loop invariant product_in_range(xs[0]) && product_in_range(xs[1]) &&
                       product_in_range(xs[2]) && product_in_range(xs[3]);
        loop invariant in_range(a) && in_range(b) && in_range(c) && in_range(d);
        loop invariant a <= b && c <= d;
        loop invariant max_val == b*d || max_val == a*d || max_val == b*c || max_val == a*c;
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
