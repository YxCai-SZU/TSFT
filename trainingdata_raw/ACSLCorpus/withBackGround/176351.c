#include <limits.h>

/*@
    predicate valid_range(integer x) = 2 <= x <= 100;

    logic integer compute_res(integer x, integer y) = x * y - (x + y) + 1;

    lemma res_positive: \forall integer x, y; valid_range(x) && valid_range(y) ==> compute_res(x, y) > 0;
*/

/*@
    requires valid_range(x) && valid_range(y);
    ensures \result == compute_res(x, y);
    ensures \result > 0;
    assigns \nothing;
*/
int func(int x, int y)
{
    int res;

    //@ assert x >= 2 && y >= 2;
    //@ assert x <= 100 && y <= 100;
    //@ assert x * y >= 2 * 2;
    //@ assert x * y <= 100 * 100;
    //@ assert x + y >= 2 + 2;
    //@ assert x + y <= 100 + 100;
    //@ assert x * y - (x + y) >= 2 * 2 - (100 + 100);
    //@ assert x * y - (x + y) + 1 > 0;

    res = x * y - (x + y) + 1;
    return res;
}
