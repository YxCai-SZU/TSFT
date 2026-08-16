#include <stdbool.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate product_in_range(integer v) = -1000000000000000000 <= v <= 1000000000000000000;
    logic integer product(integer x, integer y) = x * y;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    requires a <= b && c <= d;
    ensures \result == product(b,d) || \result == product(a,c) || \result == product(a,d) || \result == product(b,c);
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long d)
{
    long long xs[4];
    long long max_val;
    int i;

    //@ assert product_in_range(product(a,c));
    //@ assert product_in_range(product(a,d));
    //@ assert product_in_range(product(b,c));
    //@ assert product_in_range(product(b,d));

    xs[0] = a * c;
    xs[1] = a * d;
    xs[2] = b * c;
    xs[3] = b * d;

    max_val = xs[0];
    i = 1;

    /*@
        loop invariant 1 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_val == xs[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_val >= xs[j];
        loop invariant product_in_range(product(a,c));
        loop invariant product_in_range(product(a,d));
        loop invariant product_in_range(product(b,c));
        loop invariant product_in_range(product(b,d));
        loop invariant product_in_range(max_val);
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

    //@ assert max_val == product(b,d) || max_val == product(a,c) || max_val == product(a,d) || max_val == product(b,c);
    return max_val;
}
