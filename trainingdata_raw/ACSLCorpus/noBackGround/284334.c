#include <stdbool.h>

/*@
    requires 1 <= A <= 100;
    requires 1 <= B <= 100;
    requires 1 <= C <= 100;
    ensures \result == true <==> (A == B && B == C);
    assigns \nothing;
 */
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    bool result;
    
    //@ assert 1 <= A <= 100;
    //@ assert 1 <= B <= 100;
    //@ assert 1 <= C <= 100;
    
    if (A == B && B == C)
    {
        result = true;
        //@ assert ((A) == (B) && (B) == (C));
    }
    else
    {
        //@ assert A != B || B != C;
        result = false;
    }
    
    //@ assert result == true <==> (A == B && B == C);
    return result;
}
