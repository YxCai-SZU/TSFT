#include <stdbool.h>

/*@
    requires 1 <= A && A <= 9;
    requires 1 <= B && B <= 9;
    requires 1 <= C && C <= 9;
    ensures \result == (A < B && B < C);
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    bool result;
    
    //@ assert 1 <= A && A <= 9;
    //@ assert 1 <= B && B <= 9;
    //@ assert 1 <= C && C <= 9;
    
    if (A < B && B < C) {
        //@ assert A < B && B < C;
        result = true;
    } else {
        //@ assert !(A < B && B < C);
        result = false;
    }
    
    //@ assert result == (A < B && B < C);
    return result;
}
