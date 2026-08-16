#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    predicate result_constraints(integer a, integer b, integer res) =
        res <= a && res <= b && res > 0 && a % res == 0 && b % res == 0;

    logic integer min_val(integer a, integer b) =
        a < b ? a : b;
*/

/*@
    requires valid_input(a, b);
    assigns \nothing;
    ensures result_constraints(a, b, \result);
*/
unsigned int func(unsigned int a, unsigned int b) {
    unsigned int d;
    unsigned int res;
    unsigned int min_val;

    d = 2;
    res = 1;
    min_val = a < b ? a : b;

    /*@
        loop invariant 1 <= a <= 100 && 1 <= b <= 100;
        loop invariant res <= a && res <= b && res > 0;
        loop invariant a % res == 0 && b % res == 0;
        loop invariant 2 <= d <= min_val + 1;
        loop assigns d, res;
        loop variant min_val + 1 - d;
    */
    while (d < min_val + 1) {
        if (a % d == 0 && b % d == 0) {
            res = d;
        }
        d += 1;
    }
    return res;
}
