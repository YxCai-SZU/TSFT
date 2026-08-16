#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result >= 0;
*/
int32_t func(uint32_t n) {
    int32_t result;
    uint32_t quotient;
    uint32_t remainder;
    
    if (n % 2 == 0) {
        result = 0;
    } else {
        quotient = 0;
        remainder = n;
        
        /*@
            loop invariant 1 <= n <= 100;
            loop invariant 0 <= quotient <= n / 3;
            loop invariant remainder == n - 3 * quotient;
            loop invariant remainder >= 0;
            loop assigns quotient, remainder;
            loop variant remainder;
        */
        while (remainder >= 3) {
            remainder -= 3;
            quotient += 1;
        }
        
        if (remainder == 0) {
            result = 1;
        } else {
            result = 2;
        }
    }
    
    //@ assert result >= 0;
    return result;
}

int main() {
    return 0;
}
