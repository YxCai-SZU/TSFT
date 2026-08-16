#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 9 && 1 <= (B) && (B) <= 9);
    ensures
        (\result == A + B && \result < 10) ||
        (\result == A + B - 10 && \result >= 0);
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B)
{
    int64_t sum;
    int64_t result;

    //@ assert (1 <= (A) && (A) <= 9 && 1 <= (B) && (B) <= 9);
    
    sum = A + B;
    
    if (sum < 10)
    {
        result = sum;
        //@ assert result == A + B && result < 10;
    }
    else
    {
        result = sum - 10;
        //@ assert result == A + B - 10 && result >= 0;
    }
    
    //@ assert result == (((A) + (B) < 10) ? ((A) + (B)) : ((A) + (B) - 10));
    return result;
}
