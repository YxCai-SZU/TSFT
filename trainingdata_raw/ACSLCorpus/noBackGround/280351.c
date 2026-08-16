#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == (n % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned int n) {
    unsigned int lsb;
    int remainder;
    
    lsb = n & 1;
    remainder = (int)n;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= remainder <= n;
        loop invariant remainder % 2 == ((n) % 2);
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2) {
        remainder -= 2;
    }
    
    //@ assert remainder == ((n) % 2);
    
    return remainder != 0;
}
