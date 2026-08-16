#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures (((a) >= 5 ==> (\result) == 100) &&
        ((a) < 5 ==> (\result) == 0));
    assigns \nothing;
*/
int32_t func(uint32_t a)
{
    int32_t result;
    
    //@ assert (1 <= (a) && (a) <= 10);
    
    if (a >= 5) {
        //@ assert a >= 5;
        result = 100;
    } else {
        //@ assert a < 5;
        result = 0;
    }
    
    //@ assert (((a) >= 5 ==> (result) == 100) &&         ((a) < 5 ==> (result) == 0));
    return result;
}
