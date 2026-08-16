#include <stdbool.h>

/*@
    requires (1 <= (n) <= 10000 && 0 <= (a) <= 1000);
    ensures \result == (n % 500 <= a);
    assigns \nothing;
*/
bool func(int n, int a) {
    int quotient = 0;
    int remainder = n;
    int divisor = 500;

    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= a <= 1000;
        loop invariant 0 <= quotient <= n / divisor;
        loop invariant remainder == n - quotient * divisor;
        loop invariant 0 <= remainder;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        quotient += 1;
        remainder -= divisor;
    }

    //@ assert remainder == n - quotient * divisor;
    //@ assert 0 <= quotient * 500 <= 10000;
    //@ assert remainder == n % 500;

    return remainder <= a;
}
