#include <stdbool.h>

/*@
    predicate in_range(integer x) = -1000000000 <= x <= 1000000000;
    predicate product_in_range(integer x) = -1000000000000000000 <= x <= 1000000000000000000;
*/

/*@
    logic integer product(integer x, integer y) = x * y;
*/

/*@
    lemma product_range:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> product_in_range(product(a, b));
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    requires a <= b && c <= d;
    ensures \result == product(b, d) || \result == product(b, c) || 
            \result == product(a, d) || \result == product(a, c);
*/
long func(long a, long b, long c, long d)
{
    long v[4];
    long max_val;
    int i;

    //@ assert product_in_range(product(a, c));
    v[0] = a * c;

    //@ assert product_in_range(product(a, d));
    v[1] = a * d;

    //@ assert product_in_range(product(b, c));
    v[2] = b * c;

    //@ assert product_in_range(product(b, d));
    v[3] = b * d;

    max_val = v[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_val == v[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_val >= v[j];
        loop invariant product_in_range(max_val);
        loop invariant i > 0 ==> 
            max_val == product(b, d) || max_val == product(b, c) || 
            max_val == product(a, d) || max_val == product(a, c);
        loop assigns i, max_val;
        loop variant 4 - i;
    */
    while (i < 4)
    {
        if (v[i] > max_val)
        {
            max_val = v[i];
        }
        i = i + 1;
    }

    return max_val;
}
