#include <limits.h>

/*@
    predicate a_in_range(integer a) = 3 <= a <= 20;
    predicate b_in_range(integer b) = 3 <= b <= 20;
    predicate res_in_range(integer res) = 0 <= res <= 40;

    logic integer compute_res(integer a, integer b) =
        b > a ? 2 * b - a - 1 :
        b < a ? 2 * a - b - 1 :
        a + b;

    lemma res_nonnegative:
        \forall integer a, b;
        a_in_range(a) && b_in_range(b) ==> compute_res(a, b) >= 0;

    lemma res_upper_bound:
        \forall integer a, b;
        a_in_range(a) && b_in_range(b) ==> compute_res(a, b) <= 40;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures res_in_range(\result);
    assigns \nothing;
*/
int func(int a, int b)
{
    int res;

    //@ assert a_in_range(a) && b_in_range(b);

    if (b > a) {
        res = 2 * b - a - 1;
        //@ assert res == compute_res(a, b);
    } else if (b < a) {
        res = 2 * a - b - 1;
        //@ assert res == compute_res(a, b);
    } else {
        res = a + b;
        //@ assert res == compute_res(a, b);
    }

    //@ assert res_in_range(res);
    return res;
}
