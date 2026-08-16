#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - ((n) / 15) * 200);
    assigns \nothing;
*/
int32_t func(uint32_t n) {
    int32_t x;
    int32_t quotient = 0;
    int32_t remainder;
    int32_t y;
    int32_t ans;
    
    //@ assert (1 <= (n) && (n) <= 100);
    x = (int32_t)n * 800;
    remainder = (int32_t)n;
    
    /*@
        loop invariant 1 <= n && n <= 100;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop invariant remainder == (int32_t)n - quotient * 15;
        loop invariant quotient <= (int32_t)n / 15;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 15) {
        //@ assert remainder >= 15;
        quotient = quotient + 1;
        remainder = remainder - 15;
        //@ assert remainder == (int32_t)n - quotient * 15;
    }
    
    //@ assert quotient * 15 + remainder == (int32_t)n;
    //@ assert remainder < 15;
    y = quotient * 200;
    ans = x - y;
    
    //@ assert quotient == (int32_t)n / 15;
    //@ assert ans == (int32_t)n * 800 - ((int32_t)n / 15) * 200;
    
    return ans;
}
