#include <limits.h>

/*@
    requires (1 <= (X) <= 100000);
    ensures \result >= 0;
    ensures \result == (((X) / 500) * 1000 + ((X) % 500 / 5) * 5);
    assigns \nothing;
*/
int func(int X) {
    int quotient_500;
    int remainder_500;
    int quotient_5;
    int remainder_5;
    int result;
    
    quotient_500 = 0;
    remainder_500 = X;
    
    /*@
        loop invariant 1 <= X <= 100000;
        loop invariant 0 <= quotient_500 <= X / 500;
        loop invariant remainder_500 == X - quotient_500 * 500;
        loop invariant remainder_500 >= 0;
        loop assigns quotient_500, remainder_500;
        loop variant remainder_500;
    */
    while (remainder_500 >= 500) {
        //@ assert remainder_500 >= 500;
        quotient_500 = quotient_500 + 1;
        remainder_500 = remainder_500 - 500;
    }
    
    quotient_5 = 0;
    remainder_5 = remainder_500;
    
    /*@
        loop invariant 1 <= X <= 100000;
        loop invariant 0 <= quotient_5 <= remainder_500 / 5;
        loop invariant remainder_5 == remainder_500 - quotient_5 * 5;
        loop invariant remainder_5 >= 0;
        loop assigns quotient_5, remainder_5;
        loop variant remainder_5;
    */
    while (remainder_5 >= 5) {
        //@ assert remainder_5 >= 5;
        quotient_5 = quotient_5 + 1;
        remainder_5 = remainder_5 - 5;
    }
    
    result = quotient_500 * 1000 + quotient_5 * 5;
    //@ assert result == (((X) / 500) * 1000 + ((X) % 500 / 5) * 5);
    return result;
}
