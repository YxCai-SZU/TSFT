#include <stdbool.h>

/*@
    requires (1 <= (A) <= 13) && (1 <= (B) <= 13) && (1 <= (C) <= 13);
    ensures \result == ((A + B + C) >= 22);
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    unsigned int sum;
    
    sum = A + B + C;
    
    if (sum >= 22)
    {
        return true;
    }
    else
    {
        //@ assert sum < 22;
        return false;
    }
}
