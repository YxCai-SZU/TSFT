#include <limits.h>

/*@
    predicate bounds(integer x, integer y) =
        2 <= x <= 100 && 2 <= y <= 100;

    logic integer expression(integer x, integer y) =
        x * y - x - y + 1;

    lemma expr_positive: \forall integer x, y; bounds(x, y) ==> expression(x, y) > 0;
    lemma expr_lower_bound: \forall integer x, y; bounds(x, y) ==> x * y >= x + y;
    lemma expr_min_product: \forall integer x, y; bounds(x, y) ==> x * y >= 4;
    lemma expr_max_product: \forall integer x, y; bounds(x, y) ==> x * y <= 10000;
    lemma expr_min_sum: \forall integer x, y; bounds(x, y) ==> x + y >= 4;
    lemma expr_max_sum: \forall integer x, y; bounds(x, y) ==> x + y <= 200;
*/

/*@
    requires 2 <= x <= 100;
    requires 2 <= y <= 100;
    ensures \result == x * y - x - y + 1;
    ensures \result > 0;
    assigns \nothing;
*/
int func(int x, int y)
{
    int result;

    //@ assert x > 1 && x <= 100;
    //@ assert y > 1 && y <= 100;
    //@ assert x * y >= x + y;
    //@ assert x * y >= 4;
    //@ assert x * y <= 10000;
    //@ assert x + y >= 4;
    //@ assert x + y <= 200;

    result = x * y - x - y + 1;

    return result;
}
