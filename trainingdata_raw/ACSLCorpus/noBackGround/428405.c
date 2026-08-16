#include <limits.h>

/*@
    requires (1 <= (x) && (x) <= 1000);
    ensures \result == ((x) / (3));
    assigns \nothing;
*/
int func(int x)
{
    int quotient = 0;
    int remainder;
    int divisor = 3;
    
    if (x < 0) {
        remainder = -x;
    } else {
        remainder = x;
    }
    
    /*@
        loop invariant 1 <= x <= 1000;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop invariant remainder == x - quotient * divisor;
        loop invariant quotient <= 333;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        remainder -= divisor;
        quotient += 1;
    }
    
    if (x < 0) {
        quotient = -quotient;
    }
    
    //@ assert quotient == ((x) / (3));
    
    return quotient;
}

int main(void)
{
    return 0;
}
