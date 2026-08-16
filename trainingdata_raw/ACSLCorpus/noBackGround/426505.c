#include <stdbool.h>

/*@
    requires -100 <= A <= 100;
    requires -100 <= B <= 100;
    requires -100 <= C <= 100;
    ensures ((A) == (B) && (B) == (C)) ==> \result == 3;
    ensures (((A) == (B) || (B) == (C) || (A) == (C)) && !((A) == (B) && (B) == (C))) ==> \result == 2;
    ensures ((A) != (B) && (B) != (C) && (A) != (C)) ==> \result == 0;
    assigns \nothing;
*/
int func(int A, int B, int C)
{
    int result = 0;
    
    //@ assert -100 <= A <= 100 && -100 <= B <= 100 && -100 <= C <= 100;
    
    if (A == B) {
        result += 1;
    }
    if (B == C) {
        result += 1;
    }
    if (A == C) {
        result += 1;
    }
    
    if (result == 3) {
        //@ assert ((A) == (B) && (B) == (C));
        return 3;
    } else if (result >= 1) {
        //@ assert (((A) == (B) || (B) == (C) || (A) == (C)) && !((A) == (B) && (B) == (C)));
        return 2;
    } else {
        //@ assert ((A) != (B) && (B) != (C) && (A) != (C));
        return 0;
    }
}
