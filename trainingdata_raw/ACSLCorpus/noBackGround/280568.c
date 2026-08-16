#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == a * b;
    ensures 1 <= \result <= 10000;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b) {
    int64_t ans;
    //@ assert 1 <= a * b <= 10000;
    ans = a * b;
    return ans;
}
