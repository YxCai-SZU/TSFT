#include <stdint.h>

/*@
    requires (1 <= (a) <= 3 && 1 <= (b) <= 3 && (a) != (b));
    ensures \result == (6 - ((a) + (b)));
    assigns \nothing;
*/
int64_t func(uint64_t a, uint64_t b)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert 1 <= a <= 3 && 1 <= b <= 3;
    //@ assert 2 <= a + b <= 6;
    //@ assert 6 >= a + b;
    //@ assert 6 - (a + b) >= 0;
    
    result = 6 - (a + b);
    
    return result;
}
