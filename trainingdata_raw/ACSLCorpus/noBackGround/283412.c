#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == 2 * 314159 * r / 100000;
*/
int64_t func(int64_t r) {
    // Variable declarations
    int64_t pi_approx;
    int64_t scaled_r;
    int64_t product;
    int64_t result;
    int64_t temp_product;
    int64_t divisor;
    
    // Initialization
    pi_approx = 314159;
    scaled_r = r * 100000;
    product = 2 * pi_approx * r;
    result = 0;
    temp_product = product;
    divisor = 100000;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 314159;
        loop invariant scaled_r == r * 100000;
        loop invariant product == 2 * pi_approx * r;
        loop invariant divisor == 100000;
        loop invariant result * divisor + temp_product == product;
        loop invariant 0 <= temp_product < divisor + product;
        loop assigns temp_product, result;
        loop variant temp_product;
    */
    while (temp_product >= divisor) {
        //@ assert temp_product >= divisor;
        temp_product -= divisor;
        result += 1;
    }
    
    return result;
}
