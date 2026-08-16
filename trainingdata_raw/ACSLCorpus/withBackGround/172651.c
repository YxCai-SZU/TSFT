#include <stdint.h>

/*@
    predicate is_valid_input(integer a, integer b) =
        1 <= a && a <= 20 &&
        1 <= b && b <= 20;

    predicate valid_result(integer res) =
        res == -1 || res == 0 || res == 1 || res == 2;
*/

/*@
    requires is_valid_input(a, b);
    ensures valid_result(\result);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t res;

    if (a == 1 && b == 1) {
        res = 0;
        //@ assert res == 0;
    } else if (a == 1 || b == 1) {
        res = 1;
        //@ assert res == 1;
    } else if (a == 2 && b == 2) {
        res = 0;
        //@ assert res == 0;
    } else if (a == 2 || b == 2) {
        res = 2;
        //@ assert res == 2;
    } else {
        //@ assert a != 1 && b != 1 && a != 2 && b != 2;
        res = -1;
        //@ assert res == -1;
    }

    //@ assert valid_result(res);
    return res;
}
