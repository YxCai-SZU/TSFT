#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 20 && 1 <= (B) && (B) <= 20);
    ensures \result == A * B || \result == A + B || \result == A + B + 1;
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B)
{
    //@ assert (1 <= (A) && (A) <= 20 && 1 <= (B) && (B) <= 20);
    
    //@ assert 1 <= A * B <= 400;
    
    int64_t ans;
    
    if (A * B > A + B + 1)
    {
        ans = A * B;
    }
    else
    {
        ans = A + B + 1;
    }
    
    //@ assert ans == A * B || ans == A + B || ans == A + B + 1;
    //@ assert ans >= 0;
    
    return ans;
}
