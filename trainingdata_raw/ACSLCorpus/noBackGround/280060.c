#include <stdint.h>

/*@
    requires (0 <= (A) && (A) < (B) && (B) < (C) && (C) < (D) && (D) < (E) && (E) <= 123 &&
        0 <= (K) && (K) <= 123);
    ensures \result == E - A || \result == E - A - 1 || 
            \result == E - A - 2 || \result == E - A - 3;
    assigns \nothing;
*/
int32_t func(int32_t A, int32_t B, int32_t C, int32_t D, int32_t E, int32_t K)
{
    int32_t ans = 0;

    //@ assert (0 <= (A) && (A) < (B) && (B) < (C) && (C) < (D) && (D) < (E) && (E) <= 123 &&         0 <= (K) && (K) <= 123);
    
    if (E - A <= K) {
        ans = E - A;
        //@ assert ans == E - A;
    } else if (E - A - 1 <= K) {
        ans = E - A - 1;
        //@ assert ans == E - A - 1;
    } else if (E - A - 2 <= K) {
        ans = E - A - 2;
        //@ assert ans == E - A - 2;
    } else {
        ans = E - A - 3;
        //@ assert ans == E - A - 3;
    }

    //@ assert ans == E - A || ans == E - A - 1 || ans == E - A - 2 || ans == E - A - 3;
    return ans;
}
