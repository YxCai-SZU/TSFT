#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100);
    ensures \result == (3 * (a) * (a));
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at scope top
    int64_t result;
    
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert 3 * a <= 300;
    //@ assert (3 * a) * a <= 30000;
    
    result = 3 * a * a;
    
    //@ assert result == (3 * (a) * (a));
    return result;
}
