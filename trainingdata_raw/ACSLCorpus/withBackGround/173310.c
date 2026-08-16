#include <stdbool.h>

/*@
    predicate bounds_k(integer k) = 1 <= k <= 100;
    predicate bounds_x(integer x) = 1 <= x <= 100000;
    predicate product_bounded(integer k) = 500 * k <= 50000;
*/

/*@
    requires bounds_k(k) && bounds_x(x);
    ensures \result == (500 * k >= x);
    assigns \nothing;
*/
bool func(int k, int x)
{
    // Variable declarations at scope top
    int en;
    int en_count;
    int target;
    int total_en;
    bool result;

    en = 500;
    en_count = k;
    target = x;

    //@ assert bounds_k(k);
    //@ assert bounds_x(x);
    //@ assert product_bounded(k);

    total_en = en * en_count;
    result = total_en >= target;

    return result;
}
