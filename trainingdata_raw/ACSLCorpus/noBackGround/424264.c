#include <stdint.h>

/*@
    requires (0 <= (A) <= 100 && 0 <= (P) <= 100);
    ensures \result >= 0 && \result <= A * 3 + P;
*/
int64_t func(int64_t A, int64_t P)
{
    int64_t sum;
    int64_t ans;
    int is_even;

    //@ assert (0 <= (A) <= 100 && 0 <= (P) <= 100);
    sum = A * 3 + P;
    ans = 0;
    is_even = 1;

    /*@
        loop invariant 0 <= sum <= ((A) * 3 + (P));
        loop invariant 0 <= ans <= (((A) * 3 + (P)) - sum) / 2;
        loop invariant (0 <= (A) <= 100 && 0 <= (P) <= 100);
        loop invariant is_even == 0 || is_even == 1;
        loop assigns sum, ans, is_even;
        loop variant sum;
    */
    while (sum >= 2 && is_even) {
        //@ assert sum >= 2 && is_even == 1;
        sum -= 2;
        ans += 1;
        is_even = 0;
    }

    /*@
        loop invariant 0 <= sum <= ((A) * 3 + (P));
        loop invariant 0 <= ans <= (((A) * 3 + (P)) - sum) / 2;
        loop invariant (0 <= (A) <= 100 && 0 <= (P) <= 100);
        loop invariant is_even == 0 || is_even == 1;
        loop assigns sum, is_even;
        loop variant sum;
    */
    while (sum >= 1 && !is_even) {
        //@ assert sum >= 1 && is_even == 0;
        sum -= 1;
        is_even = 1;
    }

    //@ assert ans >= 0;
    //@ assert ans <= ((A) * 3 + (P));
    return ans;
}
