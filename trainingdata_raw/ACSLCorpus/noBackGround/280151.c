#include <stdint.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> ((n) % 2 == 0);
    ensures \result == 1 ==> ((n) % 2 != 0);
*/
int32_t func(uint32_t n) {
    int32_t result;
    
    if (n % 2 == 0) {
        //@ assert ((n) % 2 == 0);
        result = 0;
    } else {
        //@ assert ((n) % 2 != 0);
        result = 1;
    }
    
    return result;
}
