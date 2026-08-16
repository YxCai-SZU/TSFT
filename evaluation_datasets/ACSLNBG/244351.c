#include <stdint.h>


int32_t func(uint32_t n, uint32_t m) {
    int32_t result;
    
    if (m >= 13) {
        //@ assert ((m) >= 13);
        result = 0;
    } else if (m >= 6) {
        //@ assert ((m) >= 6 && (m) <= 12);
        result = 1;
    } else {
        //@ assert ((m) <= 5);
        result = 2;
    }
    
    return result;
}
