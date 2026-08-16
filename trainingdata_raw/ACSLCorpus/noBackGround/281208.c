#include <stdint.h>

/*@
    requires ((a) >= 0);
    ensures \result == ((a) ^ 0);
    ensures \result == a;
*/
int32_t test_a(int32_t a)
{
    int32_t result;
    
    //@ assert ((a) ^ 0) == a;
    
    result = a ^ 0;
    
    //@ assert result == ((a) ^ 0);
    //@ assert result == a;
    
    return result;
}
