#include <stdbool.h>


bool func(long A, long B, long C)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert A <= B;
    
    result = (A <= C && C <= B);
    return result;
}
