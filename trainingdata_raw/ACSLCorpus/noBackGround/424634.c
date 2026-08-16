#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result >= 0;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    uint32_t min1;
    uint32_t min2;
    int32_t result;
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    if (a < b) {
        min1 = a;
    } else {
        min1 = b;
    }
    
    if (c < d) {
        min2 = c;
    } else {
        min2 = d;
    }
    
    //@ assert min1 == ((a) < (b) ? (a) : (b));
    //@ assert min2 == ((c) < (d) ? (c) : (d));
    
    if (min1 < min2) {
        //@ assert min2 - min1 >= 0;
        result = (int32_t)(min2 - min1);
    } else {
        //@ assert min1 - min2 >= 0;
        result = (int32_t)(min1 - min2);
    }
    
    //@ assert result >= 0;
    return result;
}
