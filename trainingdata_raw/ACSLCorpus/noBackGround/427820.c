#include <stdint.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100);
    ensures \result >= 0 && \result <= B;
    ensures \result == 0 || \result == B - A * 2;
    assigns \nothing;
*/
int32_t func(int32_t A, int32_t B)
{
    // Variable declarations at scope top
    int32_t ans;

    //@ assert 1 <= A && A <= 100;
    //@ assert 1 <= B && B <= 100;
    //@ assert A * 2 <= 200;
    //@ assert B - A * 2 <= 100;

    ans = B - A * 2;
    if (ans < 0) {
        ans = 0;
    }

    //@ assert ans >= 0 && ans <= B;
    //@ assert ans == 0 || ans == B - A * 2;

    return ans;
}
