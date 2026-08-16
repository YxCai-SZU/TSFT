#include <stdbool.h>


bool func(unsigned int x)
{
    bool result;
    
    //@ assert (x & 1) == (x & 1);
    
    result = (x & 0x1) == 0x1;
    
    //@ assert result == ((x & 1) == 1);
    
    return result;
}
