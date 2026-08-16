#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (r) <= 4111);
    ensures \result == ((n) < 10 ? (r) + 100 * (10 - (n)) : (r));
    ensures \result <= 5111;
*/
int64_t func(int64_t n, int64_t r)
{
    uint64_t n_unsigned;
    uint64_t r_unsigned;
    uint64_t res_unsigned;
    int64_t result;

    //@ assert r <= 4111;
    r_unsigned = (uint64_t)r;

    if (n < 10) {
        //@ assert 10 - n >= 0;
        n_unsigned = (uint64_t)(10 - n);
    } else {
        n_unsigned = 0;
    }

    //@ assert n_unsigned <= 10;
    //@ assert 100 * n_unsigned <= 1000;

    res_unsigned = r_unsigned + 100 * n_unsigned;

    //@ assert res_unsigned <= 5111;

    if (n < 10) {
        result = (int64_t)res_unsigned;
    } else {
        result = r;
    }

    return result;
}
