#include <stdbool.h>

/*@
    predicate is_valid_range(integer a) = 1 <= a <= 100;
    
    logic integer compute_discount(integer a) = (a / 15) * 200;
    
    lemma discount_correctness:
        \forall integer a; is_valid_range(a) ==> 
            compute_discount(a) == (a / 15) * 200;
*/

/*@
    requires is_valid_range(a);
    ensures \result == a * 800 - (a / 15 * 200);
    assigns \nothing;
*/
int func(int a)
{
    int quotient;
    int remainder;
    int divisor;
    int discount;
    int result;
    
    quotient = 0;
    remainder = a;
    divisor = 15;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 0 <= quotient;
        loop invariant quotient <= a / 15;
        loop invariant remainder == a - quotient * 15;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }
    
    discount = quotient * 200;
    
    //@ assert quotient == a / 15;
    //@ assert discount == quotient * 200;
    //@ assert discount == (a / 15) * 200;
    
    result = a * 800 - discount;
    
    //@ assert result == a * 800 - (a / 15 * 200);
    
    return result;
}
