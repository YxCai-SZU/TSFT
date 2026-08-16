#include <stdint.h>
/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate product_in_range(integer x, integer y) = -1000000000000000000 <= x * y <= 1000000000000000000;
    lemma product_bound: \forall integer a, b; in_range(a) && in_range(b) ==> product_in_range(a, b);
    predicate is_valid_product(integer v, integer a, integer b, integer c, integer d) =
        v == a * c || v == a * d || v == b * c || v == b * d;
*/

/*@
    requires a >= -1000000000 && b <= 1000000000 && a <= b;
    requires c >= -1000000000 && d <= 1000000000 && c <= d;
    ensures \result == a * d || \result == a * c || \result == b * d || \result == b * c;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t v[4];
    int64_t max_value;
    int64_t i;

    //@ assert product_in_range(a, c);
    v[0] = a * c;
    //@ assert product_in_range(a, d);
    v[1] = a * d;
    //@ assert product_in_range(b, c);
    v[2] = b * c;
    //@ assert product_in_range(b, d);
    v[3] = b * d;

    max_value = v[0];
    i = 1;
    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \forall integer k; 0 <= k < 4 ==> is_valid_product(v[k], a, b, c, d);
        loop invariant is_valid_product(max_value, a, b, c, d);
        loop invariant \forall integer k; 0 <= k < i ==> max_value >= v[k];
        loop assigns i, max_value;
    */
    while (i < 4)
    {
        if (v[i] > max_value)
        {
            max_value = v[i];
        }
        i = i + 1;
    }
    return max_value;
}
