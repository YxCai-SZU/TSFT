#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) + (a) * (a) + (a) * (a) * (a));
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at top of scope
    int64_t result;

    //@ assert (1 <= (a) <= 10);
    //@ assert 1 <= a + a * a + a * a * a <= 1110;

    result = a + a * a + a * a * a;
    
    //@ assert result == ((a) + (a) * (a) + (a) * (a) * (a));
    return result;
}
