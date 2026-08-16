#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer min(integer x, integer y) = x < y ? x : y;

    logic integer compute_result(integer a, integer b, integer c, integer d) =
        a + b + c + d - 3 * min(a, b);
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    requires valid_range(d);
    ensures \result == compute_result(a, b, c, d);
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t train;
    int64_t taxi;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);

    if (a < b) {
        train = a;
    } else {
        train = b;
    }

    //@ assert train == min(a, b);

    taxi = a + b + c + d - train * 3;

    //@ assert taxi == compute_result(a, b, c, d);

    return taxi;
}
