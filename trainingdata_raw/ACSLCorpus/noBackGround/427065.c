#include <stdint.h>

/*@
    requires (1 <= (k) <= 200);
    ensures \result == (((k) / 2) + ((k) % 2));
    assigns \nothing;
*/
int32_t func(uint32_t k)
{
    int32_t result = 0;
    
    //@ assert (1 <= (k) <= 200);
    
    if (k % 2 == 0) {
        result = (int32_t)(k / 2);
    } else {
        result = (int32_t)(k / 2) + 1;
    }
    
    //@ assert result == (((k) / 2) + ((k) % 2));
    return result;
}

