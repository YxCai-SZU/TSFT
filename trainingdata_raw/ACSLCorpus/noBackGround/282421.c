#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == a - 2*b || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t result;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    if (a - 2 * b >= 0) {
        result = a - 2 * b;
        //@ assert result == a - 2*b;
    } else {
        result = 0;
        //@ assert result == 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == a - 2*b || result == 0;
    
    return result;
}
