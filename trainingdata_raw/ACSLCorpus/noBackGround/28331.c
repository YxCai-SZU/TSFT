#include <stdint.h>

/*@
    requires 0 <= x <= 8 && 0 <= y <= 8;
    ensures \result <= 64;
    assigns \nothing;
*/
uint32_t verify_nonlinear_arith_func(uint32_t x, uint32_t y) {
    uint32_t product;
    product = x * y;
    
    //@ assert product <= 64;
    return product;
}

/*@
    requires 0 <= x <= 8 && 0 <= y <= 8 && 0 <= z <= 8;
    ensures \result <= 72;
    assigns \nothing;
*/
uint32_t verify_upper_bound_func(uint32_t x, uint32_t y, uint32_t z) {
    uint32_t product;
    uint32_t sum;
    
    product = x * y;
    //@ assert product <= 64;
    
    sum = product + z;
    //@ assert sum <= 72;
    
    return sum;
}

/*@
    requires 0 <= x <= 8 && 0 <= y <= 8 && 0 <= z <= 8;
    ensures \result <= 128;
    assigns \nothing;
*/
uint32_t verify_distributive_func(uint32_t x, uint32_t y, uint32_t z) {
    uint32_t sum1;
    uint32_t sum2;
    uint32_t term1;
    uint32_t term2;
    
    sum1 = y + z;
    term1 = x * sum1;
    //@ assert term1 <= 128;
    
    term2 = x * y + x * z;
    //@ assert term2 <= 128;
    
    return term1;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
