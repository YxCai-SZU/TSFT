#include <stdint.h>

/*@
    predicate valid_range(integer x) = 0 <= x <= 50;

    logic integer max(integer x, integer y) = (x > y) ? x : y;
    logic integer min(integer x, integer y) = (x < y) ? x : y;

    lemma max_range: \forall integer a, b; valid_range(a) && valid_range(b) ==> valid_range(max(a,b));
    lemma min_range: \forall integer a, b; valid_range(a) && valid_range(b) ==> valid_range(min(a,b));
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result >= 0;
    ensures \result <= a + b + c;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t max_bc;
    int64_t max_ab;
    int64_t min_bc;
    int64_t min_ab;
    int64_t diff;
    int64_t result;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c);

    max_bc = (b > c) ? b : c;
    //@ assert valid_range(max_bc);

    max_ab = (a > max_bc) ? a : max_bc;
    //@ assert valid_range(max_ab);

    min_bc = (b < c) ? b : c;
    //@ assert valid_range(min_bc);

    min_ab = (a < min_bc) ? a : min_bc;
    //@ assert valid_range(min_ab);

    diff = max_ab - (min_ab + 1);
    //@ assert diff == max_ab - (min_ab + 1);

    result = (diff < 0) ? 0 : diff;
    //@ assert result >= 0;

    //@ assert result <= a + b + c;

    return result;
}
