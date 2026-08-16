#include <limits.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (((a) * (b) + 1) / 2);
    assigns \nothing;
*/
int func(int a, int b) {
    int result;
    int quotient;
    int abs_result;
    int divisor;
    
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    
    //@ assert 1 <= a * b <= 100 * 100;
    
    result = a * b + 1;
    quotient = 0;
    abs_result = (result < 0) ? -result : result;
    divisor = 2;
    
    /*@
        loop invariant 0 <= abs_result;
        loop invariant result == a * b + 1;
        loop invariant abs_result + quotient * divisor == result;
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 100;
        loop assigns abs_result, quotient;
        loop variant abs_result;
    */
    while (abs_result >= divisor) {
        abs_result -= divisor;
        quotient += 1;
    }
    
    if (result < 0) {
        quotient = -quotient;
    }
    
    //@ assert quotient == (((a) * (b) + 1) / 2);
    return quotient;
}
