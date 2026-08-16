#include <stdint.h>

/*@
    requires (0 <= (A) && (A) <= 100 && 0 <= (P) && (P) <= 100);
    ensures \result <= A * 3 + P;
    ensures \result == (A * 3 + P) / 2;
*/
uint32_t func(uint32_t A, uint32_t P) {
    uint32_t ans = A * 3 + P;
    uint32_t quotient = 0;
    uint32_t remainder = ans;

    /*@
        loop invariant 0 <= quotient <= ans / 2;
        loop invariant remainder == ans - 2 * quotient;
        loop invariant (0 <= (A) && (A) <= 100 && 0 <= (P) && (P) <= 100);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 2) {
        remainder -= 2;
        quotient += 1;
    }
    ans = quotient;

    //@ assert ans == (A * 3 + P) / 2;
    return ans;
}
