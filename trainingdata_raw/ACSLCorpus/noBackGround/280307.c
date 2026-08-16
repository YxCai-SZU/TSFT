#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == ((((n)) * 800) - (((((n)) / 15)) * 200));
*/
int func(int n) {
    int x;
    int quotient;
    int remainder;
    int divisor;
    int y;
    int ans;

    //@ assert (1 <= (n) <= 100);
    //@ assert ((n) * 800) <= 80000;
    
    x = n * 800;
    
    quotient = 0;
    remainder = n;
    divisor = 15;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop invariant remainder == n - quotient * divisor;
        loop invariant quotient <= n / divisor;
        loop assigns quotient, remainder;
    */
    while (remainder >= divisor) {
        quotient = quotient + 1;
        remainder = remainder - divisor;
    }
    
    //@ assert ((quotient) * 200) <= 20000;
    
    y = quotient * 200;
    ans = x - y;
    
    //@ assert ans == ((((n)) * 800) - (((((n)) / 15)) * 200));
    return ans;
}
