#include <stdint.h>

/*@
    requires (1 <= (x) <= 1000000000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    assigns \nothing;
*/
uint64_t func(uint64_t x) {
    uint64_t result = 0;
    uint64_t temp_x = x;
    uint64_t div_500 = 0;
    uint64_t mod_500_div_5 = 0;
    
    //@ ghost uint64_t original_x = x;
    
    /*@
        loop invariant 0 <= temp_x <= original_x;
        loop invariant div_500 <= original_x / 500;
        loop invariant temp_x == original_x - div_500 * 500;
        loop invariant (1 <= (original_x) <= 1000000000);
        loop assigns temp_x, div_500;
        loop variant temp_x;
    */
    while (temp_x >= 500) {
        temp_x -= 500;
        div_500 += 1;
    }
    
    /*@
        loop invariant 0 <= temp_x <= original_x;
        loop invariant mod_500_div_5 <= original_x / 5;
        loop invariant temp_x == original_x - div_500 * 500 - mod_500_div_5 * 5;
        loop invariant (1 <= (original_x) <= 1000000000);
        loop assigns temp_x, mod_500_div_5;
        loop variant temp_x;
    */
    while (temp_x >= 5) {
        temp_x -= 5;
        mod_500_div_5 += 1;
    }
    
    result = div_500 * 1000 + mod_500_div_5 * 5;
    
    //@ assert result == (((original_x) / 500) * 1000 + (((original_x) % 500) / 5) * 5);
    
    return result;
}

int main() {
    return 0;
}
