#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0 && (\result == ((a) - (b) * 2) || \result == 0);
*/
int64_t func(int64_t a, int64_t b)
{
    // Variable declarations at scope top
    int64_t result;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    result = a - b * 2;
    
    //@ assert ((a) - (b) * 2) == result;
    
    if (result < 0) {
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == ((a) - (b) * 2) || result == 0;
    
    return result;
}
