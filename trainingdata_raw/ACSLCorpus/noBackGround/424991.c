#include <stddef.h>

/*@
    requires (0 <= (a) <= 23 && 0 <= (b) <= 23);
    ensures \result == (((a) + (b)) % 24);
    ensures 0 <= \result <= 23;
*/
size_t func(size_t a, size_t b)
{
    //@ assert (0 <= (a) <= 23 && 0 <= (b) <= 23);
    
    size_t sum;
    size_t result;
    
    sum = a + b;
    //@ assert 0 <= sum <= 46;
    
    result = sum % 24;
    //@ assert result == (((a) + (b)) % 24);
    
    return result;
}
