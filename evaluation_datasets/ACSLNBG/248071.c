#include <stdbool.h>


bool func(int n)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert -40 <= n <= 40;
    
    result = (n >= 30);
    
    //@ assert result == (n >= 30);
    
    return result;
}
