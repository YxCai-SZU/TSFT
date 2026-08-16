#include <limits.h>

/*@
    predicate valid_range(integer v) = -100 <= v <= 100;

    logic integer min(integer x, integer y) = (x < y) ? x : y;

    predicate all_conditions(integer a, integer b, integer c, integer d) =
        min(a, b) + min(c, d) == a + c ||
        min(a, b) + min(c, d) == a + d ||
        min(a, b) + min(c, d) == b + c ||
        min(a, b) + min(c, d) == b + d;

    lemma min_ab_lemma: \forall integer a, b; min(a, b) == a || min(a, b) == b;
    lemma min_cd_lemma: \forall integer c, d; min(c, d) == c || min(c, d) == d;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int min_ab;
    int min_cd;
    int result;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);

    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }
    //@ assert min_ab == a || min_ab == b;

    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }
    //@ assert min_cd == c || min_cd == d;

    result = min_ab + min_cd;
    //@ assert all_conditions(a, b, c, d);
    return result;
}
