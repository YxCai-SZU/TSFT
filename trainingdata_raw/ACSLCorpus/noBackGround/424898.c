#include <stdint.h>

/*@
    requires (0 <= (n) <= 100);
    ensures \result <= 2;
    ensures \result == (((n)/10 == 9 ? 1 : 0) + ((n)%10 == 9 ? 1 : 0));
*/
uint32_t count_nine(uint32_t n) {
    uint32_t count = 0;
    uint32_t num = n;
    uint32_t quotient = 0;
    uint32_t remainder = num;
    
    /*@
        loop invariant 0 <= quotient <= n/10;
        loop invariant remainder == n - quotient * 10;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 10) {
        quotient += 1;
        remainder -= 10;
    }
    
    //@ assert quotient == n/10;
    //@ assert remainder == n%10;
    
    if (quotient == 9) {
        count += 1;
    }
    if (remainder == 9) {
        count += 1;
    }
    
    //@ assert count == (((n)/10 == 9 ? 1 : 0) + ((n)%10 == 9 ? 1 : 0));
    return count;
}
