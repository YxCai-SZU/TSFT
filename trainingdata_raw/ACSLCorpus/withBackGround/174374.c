#include <stdint.h>

/*@ predicate valid_range(integer a) = 1 <= a <= 20; */

/*@
    requires valid_range(A) && valid_range(B);
    ensures \result == (A + B < 20 ? A + B : 2 * A + 2 * B - 20);
*/
int64_t func(int64_t A, int64_t B) {
    int64_t ans;
    //@ assert valid_range(A) && valid_range(B);
    if (A + B < 20) {
        ans = A + B;
        //@ assert ans == A + B;
    } else {
        ans = 2 * A + 2 * B - 20;
        //@ assert ans == 2 * A + 2 * B - 20;
    }
    //@ assert ans == (A + B < 20 ? A + B : 2 * A + 2 * B - 20);
    return ans;
}
