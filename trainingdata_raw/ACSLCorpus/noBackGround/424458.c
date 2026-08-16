#include <stdbool.h>

/*@
    requires -40 <= X <= 40;
    ensures \result == true ==> ((X) >= 30);
    ensures \result == false ==> ((X) < 30);
*/
bool func(int X)
{
    bool result;
    
    //@ assert X >= -40 && X <= 40;
    
    result = (X >= 30);
    
    //@ assert result == true ==> ((X) >= 30);
    //@ assert result == false ==> ((X) < 30);
    
    return result;
}
