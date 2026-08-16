#include <limits.h>

/*@
    requires (1 <= (A) <= 100 && 1 <= (B) <= 100);
    ensures \result >= 0;
    ensures \result <= A;
    ensures \result == 0 ==> A < B;
    ensures \result > 0 ==> A >= B;
    assigns \nothing;
*/
int func(int A, int B)
{
    int result;
    
    //@ assert (1 <= (A) <= 100 && 1 <= (B) <= 100);
    
    if (A < B)
    {
        result = 0;
    }
    else
    {
        result = A - B + 1;
    }
    
    //@ assert result == ((A) < (B) ? 0 : (A) - (B) + 1);
    //@ assert result >= 0;
    //@ assert result <= A;
    //@ assert result == 0 ==> A < B;
    //@ assert result > 0 ==> A >= B;
    
    return result;
}
