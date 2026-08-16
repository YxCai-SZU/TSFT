#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100000;
    
    logic integer division_result(integer x, integer divisor) = x / divisor;
    
    lemma division_property:
        \forall integer x, divisor;
        is_valid_range(x) && divisor == 100 ==>
        division_result(x, divisor) * divisor <= x;
*/

/*@
    requires is_valid_range(x);
    ensures \result == (x >= 2000 || (100 * (x / 100) <= x));
*/
bool func(int x)
{
    int quotient = 0;
    int remainder = x;
    int divisor = 100;
    int product;
    
    /*@
        loop invariant 1 <= x <= 100000;
        loop invariant 0 <= quotient;
        loop invariant quotient <= x / 100;
        loop invariant remainder == x - quotient * 100;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        remainder -= divisor;
        quotient += 1;
    }
    
    product = quotient * 100;
    
    //@ assert product == quotient * 100;
    return x >= 2000 || (product <= x);
}
