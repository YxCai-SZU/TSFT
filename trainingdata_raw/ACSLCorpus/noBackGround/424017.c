#include <stdint.h>

/*@ requires (1 <= (r) && (r) <= 100);
    requires r == (int64_t)r;
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
 */
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t area;
    
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert 3 * r <= 300;
    
    //@ assert (3 * (r) * (r)) <= 30000;
    
    area = 3 * r * r;
    
    //@ assert area == (3 * (r) * (r));
    
    return area;
}
