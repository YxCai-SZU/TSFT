#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 20);
    requires (1 <= (b) && (b) <= 20);
    ensures \result == (((a) * (b)) * ((a) * (b)));
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b) {
    int32_t product;
    
    //@ assert (1 <= (a) && (a) <= 20);
    //@ assert (1 <= (b) && (b) <= 20);
    
    //@ assert 1 <= a * b && a * b <= 400;
    product = a * b;
    
    //@ assert 1 <= product * product && product * product <= 160000;
    return product * product;
}
