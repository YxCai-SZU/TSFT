#include <limits.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 1000;
    
    logic integer division_result(integer x) = x / 3;
    
    lemma division_property:
        \forall integer x; is_valid_range(x) ==> 
            division_result(x) >= 0 && division_result(x) <= x;
*/

/*@
    requires is_valid_range(x);
    ensures \result >= 0 && \result <= x;
    ensures \result == division_result(x) || \result == division_result(x) + 1;
*/
int func(int x) {
    int quotient;
    int remainder;
    int divisor;
    
    quotient = 0;
    remainder = x;
    divisor = 3;
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= x / 3;
        loop invariant remainder == x - quotient * 3;
        loop assigns quotient, remainder;
    */
    while (remainder >= divisor) {
        remainder -= divisor;
        quotient += 1;
    }
    
    //@ assert quotient >= 0 && quotient <= x;
    return quotient;
}
