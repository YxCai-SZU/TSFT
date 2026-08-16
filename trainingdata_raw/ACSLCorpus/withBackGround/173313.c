#include <limits.h>

/*@
    predicate is_in_range(integer v) =
        -1000000000 <= v <= 1000000000;

    predicate product_in_range(integer x, integer y) =
        -1000000000000000000 <= x * y <= 1000000000000000000;

    lemma product_bound:
        \forall integer a, b;
            is_in_range(a) && is_in_range(b) ==> product_in_range(a, b);
*/

/*@
    requires is_in_range(a) && is_in_range(b) && is_in_range(c) && is_in_range(d);
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d;
*/
long long func(long long a, long long b, long long c, long long d)
{
    long long x[4];
    long long max_value;
    int i;

    //@ assert product_in_range(a, c);
    x[0] = a * c;

    //@ assert product_in_range(a, d);
    x[1] = a * d;

    //@ assert product_in_range(b, c);
    x[2] = b * c;

    //@ assert product_in_range(b, d);
    x[3] = b * d;

    max_value = x[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_value == x[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_value >= x[j];
        loop assigns i, max_value;
    */
    while (i < 4)
    {
        if (x[i] > max_value)
        {
            max_value = x[i];
        }
        i++;
    }

    return max_value;
}
