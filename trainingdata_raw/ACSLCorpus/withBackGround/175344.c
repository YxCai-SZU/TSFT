#include <stdint.h>

/*@
    predicate is_valid_x(integer x) = 1 <= x <= 1000000000000000;
    predicate valid_result(integer r) = 0 <= r <= 1;
*/

/*@
    requires is_valid_x(x);
    ensures valid_result(\result);
    assigns \nothing;
*/
uint64_t func(uint64_t x) {
    uint64_t n;
    uint64_t a;
    uint64_t b;
    uint64_t res;

    n = x / 11;
    a = n / 2;
    b = n - a;

    if (b > 0) {
        if (b == 1) {
            if (a > 0) {
                res = 1;
                //@ assert valid_result(res);
                return res;
            } else {
                //@ assert 0 <= 0 <= 1;
                res = 0;
                //@ assert valid_result(res);
                return res;
            }
        } else {
            res = 1;
            //@ assert valid_result(res);
            return res;
        }
    } else {
        if (a > 0) {
            res = 1;
            //@ assert valid_result(res);
            return res;
        } else {
            //@ assert 0 <= 0 <= 1;
            res = 0;
            //@ assert valid_result(res);
            return res;
        }
    }
}
