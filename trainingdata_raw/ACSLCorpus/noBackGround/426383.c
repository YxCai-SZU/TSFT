#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000);
    ensures \result == ((n) % 1000 == 0 ? 0 : 1000 - ((n) % 1000));
    ensures 0 <= \result && \result <= 1000;
*/
uint32_t func(uint32_t n)
{
    uint32_t result;
    
    //@ assert n >= 1 && n <= 1000000;
    
    if (n % 1000 == 0) {
        result = 0;
    } else {
        //@ assert n % 1000 != 0;
        //@ assert 1000 - (n % 1000) <= 1000;
        result = 1000 - (n % 1000);
    }
    
    //@ assert result == ((n) % 1000 == 0 ? 0 : 1000 - ((n) % 1000));
    return result;
}
