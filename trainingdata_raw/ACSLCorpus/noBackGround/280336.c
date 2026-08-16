#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - ((n) / 15) * 200);
    assigns \nothing;
*/
int func(int n) {
    int x;
    int quotient = 0;
    int remainder = n;
    int y;
    int ans;
    
    //@ assert (1 <= (n) && (n) <= 100);
    
    //@ assert n * 800 <= 100 * 800;
    x = n * 800;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= quotient <= n / 15;
        loop invariant remainder == n - quotient * 15;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 15) {
        quotient += 1;
        remainder -= 15;
    }
    
    //@ assert x - quotient * 200 >= 0;
    y = quotient * 200;
    ans = x - y;
    
    //@ assert ans == ((n) * 800 - ((n) / 15) * 200);
    return ans;
}
