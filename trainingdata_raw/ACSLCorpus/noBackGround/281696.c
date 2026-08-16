#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 100 &&
        1 <= (B) && (B) <= 100 &&
        1 <= (C) && (C) <= 100);
    ensures \result >= 0;
    ensures \result <= A + B + C;
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B, int64_t C)
{
    //@ assert A + B <= 200;
    int64_t train = A + B;
    
    if (train >= C)
    {
        return C;
    }
    else
    {
        //@ assert A + B + C <= 300;
        int64_t bus = A + B + C - train;
        
        if (bus >= C)
        {
            return C;
        }
        else
        {
            //@ assert train <= A + B + C;
            return train;
        }
    }
}
