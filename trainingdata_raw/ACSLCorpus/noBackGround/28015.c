#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (n * 800 - 200 * (n / 15));
*/
int64_t func(uint64_t n) {
    // Variable declarations at scope top
    uint64_t x;
    uint64_t quotient;
    uint64_t remainder;
    uint64_t y;
    int64_t ans;
    
    x = n * 800;
    
    // Manual division by 15
    quotient = 0;
    remainder = n;
    
    /*@
        loop invariant 0 <= quotient <= n / 15;
        loop invariant remainder == n - quotient * 15;
        loop invariant (1 <= (n) && (n) <= 100);
        loop assigns quotient, remainder;
    */
    while (remainder >= 15) {
        //@ assert remainder >= 15;
        quotient = quotient + 1;
        remainder = remainder - 15;
    }
    
    //@ assert quotient == n / 15;
    y = 200 * quotient;
    ans = (int64_t)(x - y);
    return ans;
}
