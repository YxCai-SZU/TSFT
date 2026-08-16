#include <stdbool.h>

/*@
    requires (10 <= (n) && (n) <= 99);
    ensures \result == (((n) / 10) == 9 || ((n) % 10) == 9);
    assigns \nothing;
*/
bool func(unsigned long n) {
    unsigned long quotient = 0;
    unsigned long remainder = n;
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= ((n) / 10);
        loop invariant remainder == n - 10 * quotient;
        loop invariant 0 <= remainder && remainder < 100;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 10) {
        remainder -= 10;
        quotient += 1;
    }
    
    //@ assert quotient == ((n) / 10);
    //@ assert remainder == ((n) % 10);
    
    return quotient == 9 || remainder == 9;
}
