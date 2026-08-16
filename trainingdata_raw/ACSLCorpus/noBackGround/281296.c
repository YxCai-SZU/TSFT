#include <stdbool.h>

/*@
    requires (0 <= (A) <= 123 &&
        0 <= (B) <= 123 &&
        0 <= (C) <= 123 &&
        0 <= (D) <= 123 &&
        0 <= (E) <= 123 &&
        0 <= (K) <= 123 &&
        (A) < (B) && (B) < (C) && (C) < (D) && (D) < (E));
    ensures \result == (((E) - (A)) <= K);
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C,
          unsigned int D, unsigned int E, unsigned int K)
{
    bool ans;
    //@ assert (0 <= (A) <= 123 &&         0 <= (B) <= 123 &&         0 <= (C) <= 123 &&         0 <= (D) <= 123 &&         0 <= (E) <= 123 &&         0 <= (K) <= 123 &&         (A) < (B) && (B) < (C) && (C) < (D) && (D) < (E));
    
    ans = (E - A) <= K;
    
    //@ assert ans == (((E) - (A)) <= K);
    return ans;
}
