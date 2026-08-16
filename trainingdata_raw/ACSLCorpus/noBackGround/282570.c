#include <stdbool.h>

/*@
    requires true;
    ensures \result == ((x & 0x0000FFFF) != 0);
    assigns \nothing;
*/
bool func(unsigned int x)
{
    unsigned int result;
    
    //@ assert (x & 0x0000FFFF) == (x & 0x0000FFFF);
    
    result = x & 0x0000FFFF;
    
    //@ assert result == (x & 0x0000FFFF);
    
    return result != 0;
}
