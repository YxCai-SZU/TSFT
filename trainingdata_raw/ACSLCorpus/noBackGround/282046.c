#include <stdbool.h>

/*@
    requires (0 <= (A) && (A) <= 123 &&
        0 <= (B) && (B) <= 123 &&
        0 <= (C) && (C) <= 123 &&
        0 <= (D) && (D) <= 123 &&
        0 <= (E) && (E) <= 123 &&
        0 <= (K) && (K) <= 123 &&
        (A) < (B) && (B) < (C) && (C) < (D) && (D) < (E));
    ensures \result == (K >= E - A || A + K >= 123);
    assigns \nothing;
*/
bool func(int A, int B, int C, int D, int E, int K)
{
    //@ assert (0 <= (A) && (A) <= 123 &&         0 <= (B) && (B) <= 123 &&         0 <= (C) && (C) <= 123 &&         0 <= (D) && (D) <= 123 &&         0 <= (E) && (E) <= 123 &&         0 <= (K) && (K) <= 123 &&         (A) < (B) && (B) < (C) && (C) < (D) && (D) < (E));
    
    //@ assert K >= E - A || A + K >= 123 ==> (K >= E - A || A + K >= 123);
    
    return K >= E - A || A + K >= 123;
}
