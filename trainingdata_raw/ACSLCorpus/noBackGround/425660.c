#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (k) <= 100);
    ensures \result == (n - 1) || \result == (k - 1) || \result == (n - 1 + k - 1);
    assigns \nothing;
*/
int64_t func(uint32_t n, uint32_t k) {
    // Variable declarations at the top
    int64_t result;

    //@ assert (1 <= (n) <= 100 && 1 <= (k) <= 100);

    if (n == 1 && k == 1) {
        result = 0;
        //@ assert result == (n - 1) || result == (k - 1) || result == (n - 1 + k - 1);
        return result;
    } else if (n == 1) {
        //@ assert k - 1 >= 0 && k - 1 <= 99;
        result = (int64_t)(k - 1);
        //@ assert result == (n - 1) || result == (k - 1) || result == (n - 1 + k - 1);
        return result;
    } else if (k == 1) {
        //@ assert n - 1 >= 0 && n - 1 <= 99;
        result = (int64_t)(n - 1);
        //@ assert result == (n - 1) || result == (k - 1) || result == (n - 1 + k - 1);
        return result;
    } else {
        //@ assert n - 1 + k - 1 >= 0 && n - 1 + k - 1 <= 198;
        result = (int64_t)(n - 1 + k - 1);
        //@ assert result == (n - 1) || result == (k - 1) || result == (n - 1 + k - 1);
        return result;
    }
}
