#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (a) <= (n) * (n));
    ensures \result == n * n - a;
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t a) {
    // Variable declarations at scope top
    int32_t result;
    
    // Precondition verification
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= a <= n * n;
    
    // Multiplication safety
    //@ assert n * n <= 10000;
    
    // Main computation
    result = n * n - a;
    
    // Postcondition verification
    //@ assert result == n * n - a;
    
    return result;
}
