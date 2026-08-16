#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (800 * (n) - ((n) / 15) * 200);
    assigns \nothing;
*/
int32_t func(uint32_t n) {
    // Variable declarations at top of scope
    int32_t result;
    int32_t term1;
    int32_t term2;
    int32_t temp;
    
    // Precondition verification
    //@ assert (1 <= (n) && (n) <= 100);
    
    // Bound verification for 800 * n
    //@ assert 800 * n <= 800 * 100;
    
    // Bound verification for n / 15
    //@ assert n / 15 <= 6;
    
    // Lower bound verification for 800 * n
    //@ assert 800 * n >= 800 * 1;
    
    // Lower bound verification for n / 15
    //@ assert n / 15 >= 0;
    
    // Calculate first term
    term1 = 800 * (int32_t)n;
    
    // Calculate second term
    temp = (int32_t)(n / 15);
    term2 = temp * 200;
    
    // Final calculation
    result = term1 - term2;
    
    // Postcondition verification
    //@ assert result == (800 * (n) - ((n) / 15) * 200);
    
    return result;
}

int main() {
    return 0;
}
