#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t sum;
    uint32_t result;
    uint32_t temp_sum;
    uint32_t count;
    
    sum = a + b + 1;
    result = 0;
    temp_sum = sum;
    count = 0;
    
    /*@
        loop invariant temp_sum + 2*count == sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant temp_sum >= 0;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum > 1) {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
    }
    
    //@ assert count == (((a) + (b) + 1) / 2);
    result = count;
    return result;
}
