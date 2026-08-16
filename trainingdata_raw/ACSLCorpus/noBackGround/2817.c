#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b)
{
    int32_t res;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert ((a) * (b)) <= 100 * 100;
    
    res = a * b;
    
    //@ assert res == ((a) * (b));
    return res;
}
