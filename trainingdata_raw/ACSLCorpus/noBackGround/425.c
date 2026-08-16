#include <stdint.h>
#include <stdbool.h>

/*@
    requires (\valid((x) + (0..3)) &&
        (x)[0] >= 1 && (x)[0] <= 10000 &&
        (x)[1] >= 1 && (x)[1] <= 10000 &&
        (x)[2] >= 1 && (x)[2] <= 10000 &&
        (x)[3] >= 1 && (x)[3] <= 10000);
    ensures \result == ((x)[0] * (x)[1]) || \result == ((x)[2] * (x)[3]);
    ensures \result >= 1;
    assigns \nothing;
*/
uint64_t func(uint64_t *x) {
    uint64_t product1;
    uint64_t product2;
    uint64_t result;
    
    //@ assert x[0] >= 1 && x[0] <= 10000;
    //@ assert x[1] >= 1 && x[1] <= 10000;
    
    product1 = x[0] * x[1];
    //@ assert product1 >= 1 && product1 <= 10000 * 10000;
    
    //@ assert x[2] >= 1 && x[2] <= 10000;
    //@ assert x[3] >= 1 && x[3] <= 10000;
    
    product2 = x[2] * x[3];
    //@ assert product2 >= 1 && product2 <= 10000 * 10000;
    
    if (product1 > product2) {
        result = product1;
    } else {
        result = product2;
    }
    
    //@ assert result == product1 || result == product2;
    //@ assert result >= 1;
    
    return result;
}
