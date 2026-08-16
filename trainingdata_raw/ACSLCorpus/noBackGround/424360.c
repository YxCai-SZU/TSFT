#include <stdint.h>

/*@
    requires ((0 <= ((n)) && ((n)) <= 100) && (0 <= ((x)) && ((x)) <= 100));
    ensures (((\result) == (n) * 500 - (x) || (\result) == 0) && (\result) >= 0);
*/
int64_t func(int64_t n, int64_t x) {
    // Variable declarations at scope top
    int64_t ans;
    
    // Precondition verification
    //@ assert (0 <= (n) && (n) <= 100);
    //@ assert (0 <= (x) && (x) <= 100);
    
    // Arithmetic safety verification
    //@ assert 0 <= n * 500 && n * 500 <= 50000;
    
    // Main computation
    if (n * 500 - x > 0) {
        ans = n * 500 - x;
    } else {
        ans = 0;
    }
    
    // Postcondition verification
    //@ assert ans == n * 500 - x || ans == 0;
    //@ assert ans >= 0;
    
    return ans;
}
