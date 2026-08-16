#include <stdint.h>

/*@
    requires (0 <= (a) <= 1000000000 &&
        0 <= (b) < 1000000000);
    ensures \result >= 0;
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    //@ assert (0 <= (a) <= 1000000000 &&         0 <= (b) < 1000000000);
    //@ assert ((a) * (b)) >= 0;
    //@ assert ((a) * (b)) == a * b;
    
    int64_t result;
    result = a * b;
    
    //@ assert result >= 0;
    //@ assert result == ((a) * (b));
    
    return result;
}
