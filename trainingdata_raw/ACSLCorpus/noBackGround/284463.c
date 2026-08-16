#include <stdint.h>

/*@
    requires 1 <= a <= 10;
    ensures \result == a + (a * a) + (a * a * a);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    //@ assert 1 <= a <= 10;
    //@ assert a + (a * a) >= 1;
    //@ assert a * a * a >= 1;
    //@ assert a + (a * a) <= 110;
    //@ assert a * a * a <= 1000;
    //@ assert a + (a * a) + (a * a * a) <= 1110;
    
    return a + (a * a) + (a * a * a);
}
