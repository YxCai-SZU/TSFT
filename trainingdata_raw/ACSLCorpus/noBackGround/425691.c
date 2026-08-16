#include <stdbool.h>

/*@
    requires (1 <= (B) && (B) <= (A) && (A) <= 20 &&
        1 <= (C) && (C) <= 20);
    ensures \result >= 0;
    ensures \result <= C;
    ensures C < A - B ==> \result == 0;
    ensures C >= A - B ==> \result == C - (A - B);
    assigns \nothing;
*/
int func(int A, int B, int C)
{
    int remainder;
    int result;

    remainder = A - B;
    
    //@ assert remainder == A - B;
    
    if (C < remainder)
    {
        result = 0;
        //@ assert result == 0;
    }
    else
    {
        result = C - remainder;
        //@ assert result == C - remainder;
    }
    
    return result;
}
