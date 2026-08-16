#include <stdint.h>

/*@
    requires 1 <= A <= 20;
    requires 1 <= B <= 20;
    requires 1 <= T <= 20;
    ensures \result == (T / A) * B;
*/
uint32_t func(uint32_t A, uint32_t B, uint32_t T) {
    // Variable declarations at top of scope
    uint32_t ans;
    
    // Precondition verification
    //@ assert (1 <= (A) <= 20);
    //@ assert (1 <= (B) <= 20);
    //@ assert (1 <= (T) <= 20);
    
    // Ensure no overflow in division
    //@ assert T / A <= 20;
    
    // Ensure no overflow in multiplication
    //@ assert (T / A) * B <= 400;
    
    ans = (T / A) * B;
    
    // Postcondition verification
    //@ assert ans == (T / A) * B;
    
    return ans;
}
