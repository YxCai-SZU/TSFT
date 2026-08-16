#include <limits.h>

/*@
    requires (1 <= (n) <= 10000);
    requires ((n) % 3 == 0);
    ensures \result == ((n) / 3);
    assigns \nothing;
*/
int func(int n) {
    int quotient;
    int temp_n;
    int divisor;
    
    quotient = 0;
    temp_n = n;
    divisor = 3;
    
    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant temp_n == n - quotient * divisor;
        loop invariant 0 <= quotient <= n / divisor;
        loop assigns temp_n, quotient;
        loop variant temp_n;
    */
    while (temp_n >= divisor) {
        temp_n -= divisor;
        quotient += 1;
        
        //@ assert temp_n == n - quotient * divisor;
    }
    
    //@ assert temp_n == 0;
    return quotient;
}
