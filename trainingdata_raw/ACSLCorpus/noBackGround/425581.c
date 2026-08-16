#include <limits.h>

/*@
    requires \true;
    ensures (0 <= (\result) < INT_MAX);
    ensures \result == 1;
    assigns \nothing;
*/
int func(int x)
{
    int result;
    
    //@ ghost int x_ghost = x;
    
    //@ assert 0 <= 1 < INT_MAX;
    //@ assert 1 == 1;
    
    result = 1;
    
    //@ assert (0 <= (result) < INT_MAX);
    //@ assert result == 1;
    
    return result;
}
