#include <limits.h>

/*@ requires (1 <= (r) <= 100);
    requires r == (int)r;
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
 */
int func(int r)
{
    int pi = 3;
    int result;
    
    //@ assert (1 <= (r) <= 100);
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r <= 30000;
    //@ assert pi * r * r <= 30000;
    
    result = pi * r * r;
    
    //@ assert result == (3 * (r) * (r));
    return result;
}
