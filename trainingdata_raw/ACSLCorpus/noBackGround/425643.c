#include <stdint.h>

/*@
    requires (0 <= (n) && (n) < 3);
    ensures (((n) == 0 ==> (\result) == 1) &&
        ((n) == 1 ==> (\result) == 1) &&
        ((n) == 2 ==> (\result) == 2) &&
        ((n) > 2 ==> (\result) == 0));
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t result;
    
    //@ assert n < 3;
    
    if (n == 0) {
        result = 1;
    } else if (n == 1) {
        result = 1;
    } else if (n == 2) {
        result = 2;
    } else {
        //@ assert n > 2;
        result = 0;
    }
    
    return result;
}
