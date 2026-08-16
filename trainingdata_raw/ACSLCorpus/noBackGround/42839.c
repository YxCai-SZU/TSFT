#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100000);
    ensures \result == (a / 100 * 100 <= a);
    assigns \nothing;
*/
bool func(unsigned long long a) {
    unsigned long long quotient = 0;
    unsigned long long remainder = a;
    unsigned long long divisor = 100;
    unsigned long long product;
    
    //@ assert (1 <= (a) <= 100000);
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= a / 100;
        loop invariant remainder == a - quotient * divisor;
        loop invariant (1 <= (a) <= 100000);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        quotient += 1;
        remainder -= divisor;
    }
    
    //@ assert 0 <= quotient * divisor <= 100000 * 100;
    
    product = quotient * divisor;
    
    if (product <= a) {
        //@ assert product <= a;
        return true;
    } else {
        //@ assert product > a;
        return false;
    }
}

int main() {
    return 0;
}
