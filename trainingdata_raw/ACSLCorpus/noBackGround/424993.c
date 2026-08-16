#include <stdint.h>

/*@ requires (1 <= (a) && (a) <= 100 &&
     1 <= (b) && (b) <= 100 &&
     1 <= (h) && (h) <= 100 &&
     (h) % 2 == 0);
    assigns \nothing;
    ensures \result == (((a) + (b)) * (h) / 2);
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t h) {
    // Variable declarations at top of scope
    uint64_t sum;
    uint64_t result;
    uint64_t count;
    uint64_t count_half;
    
    // Preconditions
    //@ assert (1 <= (a) && (a) <= 100 &&      1 <= (b) && (b) <= 100 &&      1 <= (h) && (h) <= 100 &&      (h) % 2 == 0);
    
    // Ensure no overflow in (a + b) * h
    //@ assert (a + b) * h <= 200 * 100;
    
    sum = (a + b) * h;
    result = 0;
    count = sum;
    count_half = 0;
    
    /*@ loop invariant count + 2 * count_half == sum;
      @ loop invariant count <= sum;
      @ loop invariant count_half <= sum / 2;
      @ loop assigns count, count_half;
      @ loop variant count;
    */
    while (count >= 2) {
        //@ assert count >= 2;
        count -= 2;
        count_half += 1;
        //@ assert count + 2 * count_half == sum;
    }
    
    result = count_half;
    
    // Postcondition
    //@ assert result == (((a) + (b)) * (h) / 2);
    
    return result;
}
