#include <stdbool.h>

/*@
    requires (1 <= (A) && (A) <= 5000 && 1 <= (B) && (B) <= 5000 && 1 <= (C) && (C) <= 5000);
    ensures \result == ((((A) + (B) == (C) || (B) + (C) == (A) || (C) + (A) == (B)) ? 1 : 0) == 1);
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    bool answer = false;
    
    //@ assert (1 <= (A) && (A) <= 5000 && 1 <= (B) && (B) <= 5000 && 1 <= (C) && (C) <= 5000);
    
    if (A + B == C) {
        answer = true;
    } else if (B + C == A) {
        answer = true;
    } else if (C + A == B) {
        answer = true;
    }
    
    //@ assert answer == ((((A) + (B) == (C) || (B) + (C) == (A) || (C) + (A) == (B)) ? 1 : 0) == 1);
    return answer;
}
