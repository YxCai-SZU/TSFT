#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    requires a == (int)a && b == (int)b;
    ensures \result == ((a) * (b)) / 2;
    ensures \result <= ((a) * (b));
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b) {
    // Variable declarations at top of scope
    uint64_t result;
    uint64_t quotient = 0;
    uint64_t remainder;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    
    //@ assert ((a) * (b)) <= 10000;
    result = a * b;
    remainder = result;
    
    /*@
        loop invariant (1 <= (a) <= 100) && (1 <= (b) <= 100);
        loop invariant result == ((a) * (b));
        loop invariant quotient <= ((a) * (b)) / 2;
        loop invariant remainder == ((a) * (b)) - 2 * quotient;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 2) {
        //@ assert remainder >= 2;
        quotient += 1;
        remainder -= 2;
    }
    
    //@ assert quotient == ((a) * (b)) / 2;
    return quotient;
}
