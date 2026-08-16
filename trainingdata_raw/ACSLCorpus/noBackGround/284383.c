#include <limits.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result == b * c - a;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    int result;
    
    //@ assert 1 <= b * c <= 10000;
    
    result = b * c - a;
    
    //@ assert result == b * c - a;
    
    return result;
}
