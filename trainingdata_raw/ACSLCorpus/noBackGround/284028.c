#include <stdbool.h>
#include <stdint.h>

/*@
    requires 0 <= x <= 1;
    ensures ((x) == 1) ==> \result == 1;
    ensures ((x) == 0) ==> \result == 0;
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    int32_t res;
    
    //@ assert 0 <= x <= 1;
    
    if (x == 1) {
        //@ assert ((x) == 1);
        res = 1;
    } else {
        //@ assert ((x) == 0);
        res = 0;
    }
    
    return res;
}
