#include <stdint.h>

/*@
    requires 0 <= A <= 123 && 0 <= B <= 123 && 0 <= C <= 123 && 0 <= D <= 123 && 0 <= E <= 123 && 0 <= K <= 123;
    requires ((A) < (B) && (B) < (C) && (C) < (D) && (D) < (E));
    ensures \result >= 0;
    ensures \result <= E - A;
*/
int32_t func(int32_t A, int32_t B, int32_t C, int32_t D, int32_t E, int32_t K)
{
    int32_t ans;
    //@ assert A < E;
    if (E - A <= K) {
        ans = 0;
        //@ assert ans == (((E) - (A) <= (K)) ? 0 : ((E) - (A) - (K)));
    } else {
        ans = E - A - K;
        //@ assert ans == (((E) - (A) <= (K)) ? 0 : ((E) - (A) - (K)));
    }
    //@ assert ans == (((E) - (A) <= (K)) ? 0 : ((E) - (A) - (K)));
    return ans;
}
