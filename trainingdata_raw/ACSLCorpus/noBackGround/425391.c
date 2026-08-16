#include <stdbool.h>

/*@
    requires (1 <= (A) <= 10);
    requires (1 <= (B) <= 10);
    requires (1 <= (C) <= 10);
    ensures \result == (C >= A && C <= A + B);
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    // Variable declarations at top of scope
    bool result;
    
    if (C < A || C > A + B)
    {
        result = false;
        //@ assert !(C >= A && C <= A + B);
        return result;
    }
    
    //@ assert C >= A && C <= A + B;
    result = true;
    return result;
}
