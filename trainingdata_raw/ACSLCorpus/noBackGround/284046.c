#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 500 &&
        1 <= (b) && (b) <= 500 &&
        1 <= (c) && (c) <= 1000);
    ensures \result >= -1;
    ensures \result <= (a + b + c) * 2;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c) {
    uint32_t sum;
    int32_t count;
    
    sum = a + b + c;
    count = 0;
    
    /*@
        loop invariant 0 <= sum <= a + b + c;
        loop invariant 0 <= count <= (a + b + c) * 2;
        loop invariant sum + count <= a + b + c;
        loop assigns sum, count;
        loop variant sum;
    */
    while (sum > 0) {
        //@ assert sum <= a + b + c;
        
        if (sum <= c) {
            sum = 0;
            count = count + 1;
        } else {
            sum = sum - c;
        }
        
        //@ assert sum + count <= a + b + c;
    }
    
    //@ assert sum == 0;
    
    if (sum == 0) {
        //@ assert count >= 0;
        return count;
    } else {
        return -1;
    }
}
