#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == 800 * n - 200 * (n / 15);
    assigns \nothing;
*/
int func(int n) {
    int x;
    int quotient;
    int remainder;
    int divisor;
    int y;
    int ans;
    
    x = 800 * n;
    
    quotient = 0;
    remainder = n;
    divisor = 15;
    
    /*@
        loop invariant 0 <= quotient <= n / 15;
        loop invariant 0 <= remainder < 15 + n;
        loop invariant remainder == n - quotient * divisor;
        loop invariant (1 <= (n) && (n) <= 100);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        remainder -= divisor;
        quotient += 1;
    }
    
    y = 200 * quotient;
    ans = x - y;
    
    //@ assert quotient == n / 15;
    //@ assert y == 200 * (n / 15);
    //@ assert x == 800 * n;
    //@ assert ans == 800 * n - 200 * (n / 15);
    
    return ans;
}
