#include <stdint.h>

/*@
    requires 1 <= a && a <= 10;
    ensures \result == a + a * a + a * a * a;
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    int64_t result;
    
    //@ assert 1 <= a && a <= 10;
    
    //@ assert a + a * a + a * a * a >= 1 + 1 * 1 + 1 * 1 * 1;
    
    result = a + a * a + a * a * a;
    
    //@ assert result == a + a * a + a * a * a;
    
    return result;
}
