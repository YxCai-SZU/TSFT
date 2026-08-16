#include <limits.h>

/*@
    requires (1 <= (a) <= 100);
    ensures \result == a * 800 - (a / 15) * 200;
    ensures INT_MIN <= \result <= INT_MAX;
*/
int func(int a) {
    int quotient = 0;
    int remainder = a;
    int divisor = 15;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert remainder == a;
    
    /*@
        loop invariant 0 <= quotient <= a / 15;
        loop invariant remainder == a - quotient * 15;
        loop invariant 0 <= remainder;
        loop invariant (1 <= (a) <= 100);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        //@ assert remainder >= divisor;
        quotient += 1;
        remainder -= divisor;
        //@ assert remainder == a - quotient * 15;
    }
    
    //@ assert 0 <= quotient <= 6;
    //@ assert 0 <= remainder < 15;
    //@ assert quotient == a / 15;
    //@ assert remainder == a % 15;
    
    //@ assert 800 <= a * 800 <= 80000;
    //@ assert 0 <= quotient * 200 <= 1200;
    
    int result = a * 800 - quotient * 200;
    //@ assert result == a * 800 - (a / 15) * 200;
    
    return result;
}

int main() {
    return 0;
}
