#include <stdint.h>

/*@
    requires (1 <= (A) <= 100 && 1 <= (B) <= 100);
    ensures \result >= 0;
    ensures \result == A - 2 * B || \result == 0;
    assigns \nothing;
*/
int32_t func(int32_t A, int32_t B)
{
    // Variable declarations at top of scope
    int32_t C;
    
    //@ assert A <= 100;
    //@ assert B <= 100;
    
    C = A - 2 * B;
    
    if (C > 0)
    {
        //@ assert C >= 0;
        //@ assert C == A - 2 * B;
        return C;
    }
    else
    {
        return 0;
    }
}
