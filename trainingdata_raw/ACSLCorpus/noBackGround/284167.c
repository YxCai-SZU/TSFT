#include <stdint.h>

/*@
    requires (0 <= (X) <= 1);
    ensures (X == 1 ==> \result == 0) && (X == 0 ==> \result == 1);
    assigns \nothing;
*/
int32_t func(uint32_t X)
{
    int32_t res;
    
    if (X == 1U) {
        res = 0;
    } else {
        //@ assert X == 0;
        res = 1;
    }
    
    return res;
}
