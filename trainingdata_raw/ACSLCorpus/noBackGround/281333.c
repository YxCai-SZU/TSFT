#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result >= 0;
    ensures \result == ((n) / 2);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t result;
    //@ assert (1 <= (n) && (n) <= 100000);
    
    if (n % 2 == 0) {
        //@ assert ((n) / 2) == (int32_t)(n / 2);
        result = (int32_t)(n / 2);
    } else {
        //@ assert ((n) / 2) == (int32_t)(n / 2);
        result = (int32_t)(n / 2);
    }
    
    //@ assert result >= 0;
    //@ assert result == ((n) / 2);
    return result;
}
