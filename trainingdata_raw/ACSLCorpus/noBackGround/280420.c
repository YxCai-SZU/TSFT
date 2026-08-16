#include <stdbool.h>

/*@
    requires (1 <= (A) && (A) <= 9) && (1 <= (B) && (B) <= 9) && (1 <= (C) && (C) <= 9);
    ensures \result == true <==> (((A) == (B) && (A) != (C)) ||
        ((A) == (C) && (A) != (B)) ||
        ((B) == (C) && (B) != (A)));
*/
bool func(int A, int B, int C)
{
    //@ assert (1 <= (A) && (A) <= 9);
    
    if ((A == B && A != C) || (A == C && A != B) || (B == C && B != A))
    {
        //@ assert (((A) == (B) && (A) != (C)) ||         ((A) == (C) && (A) != (B)) ||         ((B) == (C) && (B) != (A)));
        return true;
    }
    else
    {
        //@ assert !(((A) == (B) && (A) != (C)) ||         ((A) == (C) && (A) != (B)) ||         ((B) == (C) && (B) != (A)));
        return false;
    }
}
