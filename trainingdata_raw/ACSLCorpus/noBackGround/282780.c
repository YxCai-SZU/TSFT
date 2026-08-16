#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result >= 0 && \result <= 500;
    ensures \result == ((n) >= 13 ? 500 :
        (n) >= 6 ? 250 :
        (n) >= 2 ? 100 :
        0);
*/
int32_t func(uint32_t n)
{
    int32_t result;
    //@ assert (1 <= (n) && (n) <= 100);
    
    if (n >= 13) {
        //@ assert n >= 13;
        result = 500;
    } else if (n >= 6) {
        //@ assert n >= 6;
        result = 250;
    } else if (n >= 2) {
        //@ assert n >= 2;
        result = 100;
    } else {
        //@ assert n < 2;
        result = 0;
    }
    
    //@ assert result == ((n) >= 13 ? 500 :         (n) >= 6 ? 250 :         (n) >= 2 ? 100 :         0);
    return result;
}
