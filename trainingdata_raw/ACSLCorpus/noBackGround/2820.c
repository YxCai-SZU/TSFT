#include <stdint.h>

/*@
    requires (1 <= (m) <= 12);
    ensures (0 <= (\result) <= 48);
    assigns \nothing;
*/
int64_t func(int64_t m)
{
    // Variable declarations at scope top
    int64_t hours;
    
    //@ assert 0 <= (48 - m) <= 48;
    
    hours = 48 - m;
    
    //@ assert (0 <= (hours) <= 48);
    return hours;
}
