#include <stdbool.h>
/*@
    requires (1 <= (n) <= 100);
    ensures \result == n * 800 - (n / 15) * 200;
*/
int func(int n) {
    int result;
    int temp_n;
    int quotient;
    int remainder;
    
    result = 0;
    temp_n = n;
    quotient = 0;
    remainder = 0;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= quotient;
        loop invariant 0 <= temp_n;
        loop invariant n == temp_n + 15 * quotient;
        loop assigns quotient, temp_n;
    */
    while (temp_n >= 15) {
        //@ assert temp_n >= 15;
        quotient = quotient + 1;
        temp_n = temp_n - 15;
    }
    remainder = temp_n;
    
    //@ assert quotient == n / 15;
    result = n * 800 - quotient * 200;
    
    return result;
}
