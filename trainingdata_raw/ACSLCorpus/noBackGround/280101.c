#include <stdint.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == ((l) * (l) * (l)) / 27;
    assigns \nothing;
*/
int64_t func(uint32_t l) {
    int64_t l_64 = (int64_t)l;
    int64_t divisor = 27;
    int64_t quotient = 0;
    int64_t remainder;
    
    //@ assert 1 <= l_64 && l_64 <= 1000;
    
    remainder = l_64 * l_64 * l_64;
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant 0 <= remainder;
        loop invariant remainder == ((l_64) * (l_64) * (l_64)) - quotient * divisor;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        remainder -= divisor;
        quotient += 1;
    }
    
    //@ assert remainder < divisor;
    //@ assert remainder >= 0;
    return quotient;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
