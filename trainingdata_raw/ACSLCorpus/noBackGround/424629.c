#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (3 * (r) * (r));
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t area;
    
    //@ assert (1 <= (r) <= 100);
    //@ assert (3 * (r) * (r)) >= 0;
    //@ assert (3 * (r) * (r)) <= 3 * 100 * 100;
    
    area = 3 * r * r;
    
    //@ assert area == (3 * (r) * (r));
    //@ assert area >= 0;
    
    return area;
}
