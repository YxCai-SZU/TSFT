#include <stdint.h>

/*@
    requires (1 <= (A) <= 100) && (1 <= (B) <= 100) && (1 <= (C) <= 100);
    ensures \result == ((B) - ((A) - (C)));
*/
int64_t func(int64_t A, int64_t B, int64_t C)
{
    //@ assert (1 <= (A) <= 100);
    //@ assert (1 <= (B) <= 100);
    //@ assert (1 <= (C) <= 100);
    //@ assert ((B) - ((A) - (C))) <= 200;
    
    int64_t result;
    result = B - (A - C);
    
    //@ assert result == ((B) - ((A) - (C)));
    return result;
}
