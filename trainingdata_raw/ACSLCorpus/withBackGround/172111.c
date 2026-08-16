#include <stdbool.h>

/*@
    predicate bounds(integer d, integer t, integer s) =
        1 <= d <= 10000 &&
        1 <= t <= 10000 &&
        1 <= s <= 10000;

    lemma product_bounds: \forall integer t, s;
        bounds(1, t, s) ==> t * s <= 10000 * 10000;

    lemma product_ge_t: \forall integer t, s;
        bounds(1, t, s) ==> t * s >= t;

    lemma product_ge_s: \forall integer t, s;
        bounds(1, t, s) ==> t * s >= s;

    lemma product_ge_one: \forall integer t, s;
        bounds(1, t, s) ==> t * s >= 1;
*/

/*@
    requires bounds(d, t, s);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(int d, int t, int s)
{
    // Variable declarations at scope top
    bool result;
    long long product;

    //@ assert bounds(d, t, s);
    product = (long long)t * (long long)s;
    
    //@ assert product >= 1;
    //@ assert product <= 10000LL * 10000LL;

    result = (d <= product);
    return result;
}
