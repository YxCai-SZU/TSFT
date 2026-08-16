#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 100000 &&
        1 <= (y) && (y) <= 100000 &&
        1 <= (z) && (z) <= 100000 &&
        (y) + 2 * (z) <= (x));
    ensures \result <= x;
    ensures \result >= 0;
    ensures \result == (((x) - (z)) / ((y) + (z)));
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z) {
    uint32_t ans;
    uint32_t numerator;
    uint32_t denominator;
    
    ans = 0;
    numerator = x - z;
    denominator = y + z;
    
    /*@
        loop invariant 0 <= numerator && numerator <= x;
        loop invariant 0 <= ans && ans <= x;
        loop invariant ans * denominator + numerator == x - z;
        loop invariant denominator == y + z;
        loop assigns numerator, ans;
    */
    while (numerator >= denominator) {
        //@ assert ans < x;
        numerator -= denominator;
        ans += 1;
    }
    
    return ans;
}
