#include <stdint.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == 3 * r * r;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t area;
    
    pi = 3;
    
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert pi == 3;
    
    //@ assert pi * r <= 300;
    //@ assert pi * r * r <= 30000;
    
    area = pi * r * r;
    
    //@ assert area == 3 * r * r;
    return area;
}
