#include <stdbool.h>

/*@
    requires (1 <= (A) <= 20) && (1 <= (B) <= 20);
    ensures (((A) < 10 && (B) < 10) && \result == A * B) || 
            (((A) >= 10 || (B) >= 10) && \result == -1);
    assigns \nothing;
*/
int func(int A, int B)
{
    // Declare all variables at the top
    int result;
    
    if (A < 10 && B < 10)
    {
        //@ assert 1 <= A <= 10;
        //@ assert 1 <= B <= 10;
        //@ assert 1 <= A * B <= 100;
        result = A * B;
    }
    else
    {
        result = -1;
    }
    
    return result;
}
