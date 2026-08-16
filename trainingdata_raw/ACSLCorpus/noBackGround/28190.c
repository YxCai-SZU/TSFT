#include <stdbool.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100) && (1 <= (C) <= 100);
    ensures \result == (A == B && B == C);
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    bool result;
    unsigned int c;

    if (A == B && B == C) {
        result = true;
        //@ assert result == (A == B && B == C);
        return result;
    } else {
        c = 0;
        if (A == B) {
            c += 1;
        }
        if (B == C) {
            c += 1;
        }
        if (C == A) {
            c += 1;
        }
        if (c == 1) {
            result = false;
            //@ assert result == (A == B && B == C);
            return result;
        } else {
            //@ assert c == 0 || c == 2 || c == 3;
            result = false;
            //@ assert result == (A == B && B == C);
            return result;
        }
    }
}
