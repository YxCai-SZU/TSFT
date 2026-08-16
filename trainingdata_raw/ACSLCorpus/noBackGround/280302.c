#include <stdint.h>
#include <limits.h>

/*@
    requires 1 <= n <= 1000000000000;
    requires 1 <= m <= 1000000000000;
    ensures \result <= n + m;
    ensures \result >= 0;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m) {
    uint64_t min_val;
    uint64_t operations;
    
    // Calculate min_val
    if (n < m) {
        min_val = n;
    } else {
        min_val = m;
    }
    
    // Update n and m
    n = n - min_val;
    m = m - min_val;
    
    // Verification assertions
    //@ assert ((n) >= 0);
    //@ assert ((m) >= 0);
    //@ assert ((n) <= 1000000000000);
    //@ assert ((m) <= 1000000000000);
    //@ assert ((n) <= UINT64_MAX / (2));
    //@ assert ((n * 2) <= UINT64_MAX - (m));
    
    // Calculate operations
    if (n * 2 <= m) {
        operations = n * 2 + m % 4;
    } else {
        operations = m;
    }
    
    // Final overflow check
    //@ assert ((min_val) <= UINT64_MAX / (2));
    //@ assert ((min_val * 2) <= UINT64_MAX - (operations));
    
    return min_val * 2 + operations;
}
