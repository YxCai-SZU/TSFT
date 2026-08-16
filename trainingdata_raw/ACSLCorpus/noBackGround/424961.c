#include <stdint.h>

/*@
    requires (1 <= (A) <= 100 && 1 <= (B) <= 100);
    ensures ((\result) >= 0 && ((\result) == (A) - (B) * 2 || (\result) == 0));
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B)
{
    int64_t result;
    
    //@ assert (1 <= (A) <= 100 && 1 <= (B) <= 100);
    result = A - B * 2;
    
    if (result < 0)
    {
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == A - B * 2 || result == 0;
    
    return result;
}
