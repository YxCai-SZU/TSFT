#include <stdint.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == ((((l)) * ((l)) * ((l))) / 27);
*/
int64_t func(int64_t l) {
    // Variable declarations at scope top
    int64_t l_cubed;
    const int64_t divisor = 27;
    int64_t quotient = 0;
    int64_t remainder;
    
    // Precondition assertions
    //@ assert 1 <= l <= 1000;
    //@ assert l * l <= 1000 * 1000;
    //@ assert l * l * l <= 1000 * 1000 * 1000;
    
    l_cubed = l * l * l;
    remainder = l_cubed;
    
    /*@
        loop invariant 0 <= quotient <= l_cubed / divisor;
        loop invariant remainder == l_cubed - quotient * divisor;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        quotient += 1;
        remainder -= divisor;
    }
    
    //@ assert quotient == (l * l * l) / 27;
    return quotient;
}
