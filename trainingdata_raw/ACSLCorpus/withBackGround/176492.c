#include <limits.h>

/*@
    predicate valid_inputs(integer a, integer b, integer c, integer k) =
        1 <= a <= 50 &&
        1 <= b <= 50 &&
        1 <= c <= 50 &&
        1 <= k <= 10 &&
        a + b + c >= k;

    logic integer compute_result(integer a, integer b, integer c, integer k) =
        (k <= a ? k : a) - (k - a - b > 0 ? k - a - b : 0);
*/

/*@
    requires valid_inputs(a, b, c, k);
    ensures \result >= -c;
    ensures \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int result;
    int rst;

    //@ assert valid_inputs(a, b, c, k);

    result = 0;
    rst = k;

    if (rst <= a) {
        result = rst;
    } else {
        result = a;
    }

    rst -= a;
    if (rst > 0) {
        rst -= b;
        if (rst > 0) {
            result -= rst;
        }
    }

    //@ assert result >= -c;
    //@ assert result <= a;

    return result;
}
