#include <limits.h>

/*@
    requires \true;
    ensures ((\result) >= (a) && (\result) >= (b));
    assigns \nothing;
*/
int max(int a, int b)
{
    int result;
    
    //@ ghost int original_a = a;
    //@ ghost int original_b = b;
    
    if (a > b) {
        //@ assert a >= b;
        result = a;
    } else {
        //@ assert b >= a;
        result = b;
    }
    
    //@ assert result >= original_a;
    //@ assert result >= original_b;
    
    return result;
}
